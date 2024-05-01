#include "Shield.h"

Shield::Shield() : Card("shield") {}

void Shield::Interact(Character* character) {
    int health = character->GetHealth();
    character->SetHealth(health);
}

std::vector<std::string> Shield::GetImage() {
    return std::vector<std::string>{
        "=====================",
        "|   |`-._/\\_.-`|    |",
        "|   |    ||    |    |",
        "|   |___o()o___|    |",
        "|   |___o()o___|    |",
        "|   |__((<>))__|    |",
        "|   \\   o\\/o   /    |",
        "|    \\   ||   /     |",
        "|     \\  ||  /      |",
        "|      '.||.'       |",
        "=====================",
    };
}