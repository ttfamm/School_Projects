#include "Strike.h"

Strike::Strike() : Card("strike") {}

void Strike::Interact(Character* character) {
    int health = character->GetHealth();
    int shield = character->GetShield();
    int damage = 5 - shield;
    shield -= 5;
    if (shield < 0) {
        shield = 0;
    }
    character->SetShield(shield);
    character->SetHealth(health - damage);
}

std::vector<std::string> Strike::GetImage() {
    return std::vector<std::string>{

        "=======================",
        "|           ,/         |",
        "|         ,'/          |",
        "|       ,' /           |",
        "|     ,'  /_____,      |",
        "|   .'____    ,'       |",
        "|        /  ,'         |",
        "|       / ,'           |",
        "|      /,'             |",
        "|     /'               |",
        "=======================",
    };
}