#pragma once
#include "Card.h"

class Strike : public Card {
   public:
    Strike();
    void Interact(Character*);
    std::vector<std::string> GetImage();
};