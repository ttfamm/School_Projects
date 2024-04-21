#include "Bash.h"

Bash::Bash() : Card("Bash") {}

void Bash::Interact(Character* character) {
    int health = character->GetHealth();
    character->SetHealth(health - 5 + GetModifier());
}

std::vector<std::string> Bash::GetImage() {
    return std::vector<std::string>{
        "===============================",
        "|    _               _        |",
        "|   | |             | |       |",
        "|   | |__   __ _ ___| |__     |",
        "|   | '_ \\ / _` / __| '_ \\    |",
        "|   | |_) | (_| \\__ \\ | | |   |",
        "|   |_.__/ \\__,_|___/_| |_|   |",
        "===============================",
    };
}