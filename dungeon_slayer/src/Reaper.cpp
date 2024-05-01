#include "Reaper.h"

Reaper::Reaper() : Character() {
    AddCard(new Slash);
    SetHealth(20);
}

std::string Reaper::GetName() {
    return "reaper";
}

std::vector<std::string> Reaper::GetImage() {
    return std::vector<std::string>{
        "==============================",
        "|              ___           |",
        "|            /   \\           |",
        "|         /\\ | . . \\         |",
        "|       ////\\|     ||        |",
        "|     ////   \\ ___//\\        |",
        "|    ///      \\      \\       |",
        "|   ///       |\\      |      |",
        "|  //         | \\  \\   \\     |",
        "|  /          |  \\  \\   \\    |",
        "|             |   \\ /   /    |",
        "|             |    \\/   /    |",
        "|             |     \\/|      |",
        "|             |      \\|      |",
        "|             |       \\      |",
        "|             |        |     |",
        "|             |_________\\    |",
        "==============================",
    };
}

void Reaper::Reward(Character* character) {
    character->AddCard(new Slash);
    int shield = character->GetShield() + 3;
    character->SetShield(shield);
    int health = character->GetHealth() + 5;
    character->SetHealth(health);
}