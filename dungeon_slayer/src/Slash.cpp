#include "Slash.h"

Slash::Slash() : Card("slash") {}

void Slash::Interact(Character* character) {
    int health = character->GetHealth();
    int shield = character->GetShield();
    int damage = 4 - shield;
    shield -= 4;
    if (shield < 0) {
        shield = 0;
    }
    character->SetShield(shield);
    character->SetHealth(health - damage);
}

std::vector<std::string> Slash::GetImage() {
    return std::vector<std::string>{
        "=============================",
        "|      __                   |",
        "|    ..||..'''''''...       |",
        "|    : ||            ''.    |",
        "|    :.||...''''''....  '.  |",
        "|      ||             ''''  |",
        "|      ||                   |",
        "|      ||                   |",
        "|      ||                   |",
        "|      ||                   |",
        "|      ||                   |",
        "|      ||                   |",
        "|      ||                   |",
        "|      ||                   |",
        "|      ##                   |",
        "=============================",
    };
}
