#include "Batman.h"

Batman::Batman() : Character() {
    AddCard(new Punch);
    SetHealth(50);
}

std::string Batman::GetName() {
    return "batman";
}

std::vector<std::string> Batman::GetImage() {
    return std::vector<std::string>{
        "===============================",
        "|             .  .            |",
        "|             |\\_|\\           |",
        "|             | a_a\\          |",
        "|             | | '']         |",
        "|         ____| '-\\___        |",
        "|        /.----.___.-'\\       |",
        "|       //        _    \\      |",
        "|      //   .-. (~v~) /|      |",
        "|     |'|  /\\:  .--  / \\      |",
        "|    // |-/  \\_/____/\\/~|     |",
        "|   |/  \\ |  []_|_|_] \\ |     |",
        "|   | \\  | \\ |___   _\\ ]_}    |",
        "|   | |  '-' /   '.'  |       |",
        "|   | |     /    /|:  |       |",
        "|   | |     |   / |:  /\\      |",
        "|   | |     /  /  |  /  \\     |",
        "|   | |    |  /  /  |    \\    |",
        "|   \\ |    |/\\/  |/|/\\    \\   |",
        "|    \\|\\ |\\|  |  | / /\\/\\__\\  |",
        "|     \\ \\| | /   | |__        |",
        "|          / |   |____)       |",
        "|          |_/                |",
        "===============================",
    };
}

void Batman::Reward(Character* c) {}