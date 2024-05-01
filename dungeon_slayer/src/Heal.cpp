#include "Heal.h"

Heal::Heal() : Card("heal") {}

void Heal::Interact(Character* character) {
    int health = character->GetHealth();
    character->SetHealth(health + 5);
}

std::vector<std::string> Heal::GetImage() {
    return std::vector<std::string>{
        "================================",
        "|      .-\"\"\"-.    .-\"\"\"-.      |",
        "|     /       `..'       \\     |",
        "|    |                    |    |",
        "|    |                    |    |",
        "|     \\                  /     |",
        "|      \\                /      |",
        "|       `\\            /'       |",
        "|         `\\        /'         |",
        "|           `\\    /'           |",
        "|             `\\/'             |",
        "================================",
    };
}