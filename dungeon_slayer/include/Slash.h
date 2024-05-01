#pragma once
#include "Card.h"
#include "Slash.h"

class Slash : public Card {
   public:
    Slash();
    void Interact(Character*);
    std::vector<std::string> GetImage();
};