#pragma once
#include "Card.h"

class Fire : public Card {
   public:
    Fire();
    void Interact(Character*);
    std::vector<std::string> GetImage();
};