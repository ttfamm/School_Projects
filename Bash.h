#pragma once
#include "Card.h"

class Bash : public Card {
   public:
    Bash();
    void Interact(Character*);
    std::vector<std::string> GetImage();
};