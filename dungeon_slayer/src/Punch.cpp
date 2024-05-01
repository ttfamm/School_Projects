#include "Punch.h"

Punch::Punch() : Card("punch") {}

void Punch::Interact(Character* character) {
    int health = character->GetHealth();
    character->SetHealth(health - 3);
}

std::vector<std::string> Punch::GetImage() {
    return std::vector<std::string>{
        "========================",
        "|           --.--._    |",
        "|   ------\" _, \\___)   |",
        "|           / _/____)  |",
        "|           \\//(____)  |",
        "|   ------\\     (__)   |",
        "|          `-----\"     |",
        "========================",

    };
}