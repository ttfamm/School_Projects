#pragma once
#include "Card.h"
class Punch : public Card {
   public:
    Punch();
    void Interact(Character*);
    std::vector<std::string> GetImage();
};