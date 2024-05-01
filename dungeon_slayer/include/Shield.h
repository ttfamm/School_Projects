#pragma once
#include "Card.h"
class Shield : public Card {
   public:
    Shield();
    void Interact(Character*);
    std::vector<std::string> GetImage();
};