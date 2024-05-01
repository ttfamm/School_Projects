#include "Bat.h"

Bat::Bat() : Character() {
    AddCard(new Strike);
    SetHealth(6);
}
std::string Bat::GetName() {
    return "bat";
}

std::vector<std::string> Bat::GetImage() {
    return std::vector<std::string>{

        "======================================",
        "|       =/\\                 /\\=      |",
        "|       / \'._    (\\_/)   _.'/ \\      |",
        "|      / .''._'--(o.o)--'_.''. \\     |",
        "|     /.' _/ |`'=/ \" \\='`| \\_ `.\\    |",
        "|    /` .' `\\;-,'\\___/',-;/` '. '\\   |",
        "|   /.-'       `\\(-V-)/`       `-.\\  |",
        "|   `            \"   \"            `  |",
        "======================================",
    };
}

void Bat::Reward(Character* character) {
    character->AddCard(new Strike);
    int shield = character->GetShield() + 3;
    character->SetShield(shield);
}