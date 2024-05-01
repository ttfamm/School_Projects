#include "Web.h"

Web::Web() : Card("web") {}

void Web::Interact(Character* character) {
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

std::vector<std::string> Web::GetImage() {
    return std::vector<std::string>{
        "===========================",
        "|        \\_______/        |",
        "|    `.,-'\\_____/`-.,'    |",
        "|     /`..'\\ _ /`.,'\\     |",
        "|    /  /`.,' `.,'\\  \\    |",
        "|   /__/__/     \\__\\__\\__ |",
        "|   \\  \\  \\     /  /  /   |",
        "|    \\  \\,'`._,'`./  /    |",
        "|     \\,'`./___\\,'`./     |",
        "|    ,'`-./_____\\,-'`.    |",
        "|        /       \\        |",
        "===========================",
    };
}