#pragma once
#include "Card.h"
class Heal : public Card {
   public:
    Heal();
    void Interact(Character*);
    std::vector<std::string> GetImage();
};