#include "Fire.h"

Fire::Fire() : Card("Fire") {}

void Fire::Interact(Character* character) {
    int health = character->GetHealth();
    int shield = character->GetShield();
    int damage = 7 - shield;
    shield -= 7;
    if (shield < 0) {
        shield = 0;
    }
    character->SetShield(shield);
    character->SetHealth(health - damage);
}

std::vector<std::string> Fire::GetImage() {
    return std::vector<std::string>{
        "===============",
        "|      )      |",
        "|     ) \\     |",
        "|    / ) (    |",
        "|    \\(_)/    |",
        "===============",
    };
}