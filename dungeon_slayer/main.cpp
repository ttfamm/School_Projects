#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>

#include "All.h"
using namespace std;

void display(std::vector<std::string> image) {
    ofstream ofs("game.txt");
    for (int i = 0; i < image.size(); i++) {
        ofs << image[i] << std::endl;
    }
}

int get_width(vector<string> image) {
    if (image.size() == 0) return 0;
    return image[0].size();
}

// combines 2 vector images
std::vector<std::string> combine(std::vector<std::string> left, std::vector<std::string> right) {
    std::vector<std::string> result;
    int size = std::min(left.size(), right.size());  // picks the smaller size of the 2
    int i;
    for (i = 0; i < size; i++) {
        result.push_back(left[i] + " " + right[i]);  // puts the right and left image together
    }
    while (i < left.size()) {  // adds spaces if the left is bigger than the right
        result.push_back(left[i] + string(get_width(right) + 1, ' '));
        i++;
    }
    while (i < right.size()) {  // adds spaces if the right is bigger than the left
        result.push_back(string(get_width(left) + 1, ' ') + right[i]);
        i++;
    }
    return result;
}

// puts item image under the base image
std::vector<std::string> append(vector<string> base, vector<string> item) {
    int spaces = get_width(base) - get_width(item);

    for (int i = 0; i < item.size(); i++) {
        if (spaces > 0) {
            base.push_back(item[i] + string(spaces, ' '));
        }
    }
    return base;
}

// creates a stats line for the character to be appended to the character image
vector<string> Stats(Character* character) {
    vector<string> image;
    image.push_back("Health: " + to_string(character->GetHealth()) + " Shield: " + to_string(character->GetShield()));
    return image;
}

// handles the room logic
class Room {
   public:
    Room() {}
    // adds enemy to the enemies vector
    void AddEnemey(Character* enemy) {
        enemies.push_back(enemy);
    }
    // Player fights enemies in the room
    void Battle(Character* player) {
        vector<string> image = player->GetImage();             // Gets the image of the player (Batman)
        image = append(image, Stats(player));                  // adds the player's stats to the image
        for (int i = 0; i < player->GetCards().size(); i++) {  // adds all the player's cards to the image
            Card* card = player->GetCardAtIndex(i);            // gets card
            image = append(image, card->GetImage());           // appends card to the player's image
        }
        // creates the enemies images
        for (int i = 0; i < enemies.size(); i++) {
            vector<string> enemy_image = enemies[i]->GetImage();   // get current image of enemy
            enemy_image = append(enemy_image, Stats(enemies[i]));  // appends the stats of the current enemy to the image

            Card* card = enemies[i]->GetCardAtIndex(0);  // gets card

            if (card) {
                enemy_image = append(enemy_image, card->GetImage());  // appends card to enemies' image
            }
            image = combine(image, enemy_image);  // combines the player image and enemy image
        }

        display(image);  // writes the image to game.txt

        int cindex;
        int eindex;
        cout << "Enter position of weapon and enemy: " << endl;
        cin >> cindex >> eindex;
        if (cindex < 0 || cindex >= player->GetCards().size()) {
            cout << cindex << " is not in card range" << endl;
            return;
        }

        if (eindex < 0 || eindex >= enemies.size()) {
            cout << eindex << " is not in enemies range" << endl;
            return;
        }

        Card* pAttack = player->GetCardAtIndex(cindex);
        Character* enemy = enemies[eindex];
        // the strike card can attack multiple enemies at the same time
        if (pAttack->GetName() == "strike") {
            pAttack->Interact(enemies);
            for (int i = 0; i < enemies.size(); i++) {
                cout << "You attacked " << enemies[i]->GetName() << " with " << pAttack->GetName() << endl;
                if (enemies[i]->GetHealth() <= 0) {
                    cout << "You killed " << enemies[i]->GetName() << "#" << i << endl;
                    enemies[i]->Reward(player);
                    enemies.erase(enemies.begin() + i);
                    i--;
                }
            }
        } else {
            pAttack->Interact(enemy);
            cout << "You Attacked " << enemy->GetName() << "#" << eindex << " with " << pAttack->GetName() << endl;
            if (enemy->GetHealth() <= 0) {
                cout << "You killed " << enemy->GetName() << "#" << eindex << endl;
                enemy->Reward(player);
                enemies.erase(enemies.begin() + eindex);
            }
        }

        for (int i = 0; i < enemies.size(); i++) {
            if (enemies[i]) {
                Card* card = enemies[i]->GetCardAtIndex(0);
                if (card) {
                    card->Interact(player);
                    cout << enemies[i]->GetName() << "# " << i << " attacked you with " << card->GetName() << endl;
                }
            }
        }

        display(image);
    }

    vector<Character*>& GetEnemies() {
        return enemies;
    }

   private:
    vector<Character*> enemies;
    Character* enemy;
    int total_exp;
};

class Level {
   public:
    Level() {
    }
    Level(int size) {
        numRooms = size;
        rooms = new Room[numRooms];
        visited = new bool[numRooms];
        for (int i = 0; i < numRooms; i++) {
            visited[i] = false;
        }
    }
    Room& GetRoomAt(int index) {
        return rooms[index];
    }
    int GetNumRooms() {
        return numRooms;
    }
    bool CheckVisited(int index) {
        return visited[index];
    }
    void MarkVisited(int index) {
        visited[index] = true;
    }
    void AddEnemy(int index, Character* character) {
        rooms[index].AddEnemey(character);
    }

   private:
    Room* rooms;
    int numRooms;
    bool* visited;
};

int main(int argc, char** argv) {
    // there are four levels
    Level* levels[4];
    levels[0] = new Level(4);
    levels[1] = new Level(3);
    levels[2] = new Level(2);
    levels[3] = new Level(1);

    ifstream fin("game.config");  // reads the game.config file
    int levelNum;
    int roomNum;
    string type;
    while (fin >> levelNum >> roomNum >> type) {  // adds enemies based on levelNum, roomNum, and type
        if (type == "Rat") {
            levels[levelNum]->AddEnemy(roomNum, new Rat);
        }
        if (type == "Bat") {
            levels[levelNum]->AddEnemy(roomNum, new Bat);
        }
        if (type == "Spider") {
            levels[levelNum]->AddEnemy(roomNum, new Spider);
        }
        if (type == "Reaper") {
            levels[levelNum]->AddEnemy(roomNum, new Reaper);
        }
        if (type == "Dragon") {
            levels[levelNum]->AddEnemy(roomNum, new Dragon);
        }
    }
    Batman* batman = new Batman;

    // the main game
    cout << endl;
    cout << "Welcome to the Dungeon Slayer!" << endl;
    cout << "Defeat all the levels to escape the dungeon" << endl;

    for (int i = 0; i < 4; i++) {
        cout << endl;
        int roomindex = 0;
        if (levels[i]->GetNumRooms() > 1) {
            cout << "Pick a room 0 to " << levels[i]->GetNumRooms() - 1 << endl;
            cin >> roomindex;
            if (roomindex >= levels[i]->GetNumRooms() || roomindex < 0) {
                cout << roomindex << " not in room range" << endl;
                continue;
            }
        } else {
            cout << "You've entered the boss Room" << endl;
            cout << "Defeat the enemy to escape." << endl;
        }

        Room* room = &levels[i]->GetRoomAt(roomindex);

        while (batman->GetHealth() > 0 && room->GetEnemies().size() > 0) {
            room->Battle(batman);
        }

        if (batman->GetHealth() <= 0) {
            cout << "You died" << endl;
            return 0;
        }
        if (i < 3) {
            cout << "You moved to level " << i + 1 << endl;
        }
    }
    cout << "You Won!" << endl;
    cout << "Thank you for playing!" << endl;
    return 0;
}
