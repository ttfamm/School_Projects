#include "Spider.h"

Spider::Spider() : Character() {
    AddCard(new Web);
    SetHealth(10);
}

std::string Spider::GetName() {
    return "spider";
}

std::vector<std::string> Spider::GetImage() {
    return std::vector<std::string>{
        "==========================================================",
        "|                     /\\                                  |",
        "|                    /  \\                                 |",
        "|                   |  _ \\                  _             |",
        "|                   | / \\ \\                / \\            |",
        "|                   |/   \\ \\              /   \\           |",
        "|                   /     \\ |        /\\  /     \\          |",
        "|                  /|      \\| ~  ~  /  \\/       \\         |",
        "|          _______/_|_______\\(o)(o)/___/\\_____   \\        |",
        "|         /      /  |       (______)     \\    \\   \\_      |",
        "|        /      /   |                     \\    \\          |",
        "|       /      /    |                      \\    \\         |",
        "|      /      /     |                       \\    \\        |",
        "|     /     _/      |                        \\    \\       |",
        "|    /             _|                         \\    \\_     |",
        "|  _/                                          \\          |",
        "|                                               \\         |",
        "|                                                \\_       |",
        "==========================================================",
    };
}

void Spider::Reward(Character* character) {
    character->AddCard(new Web);
    int shield = character->GetShield() + 5;
    character->SetShield(shield);
}