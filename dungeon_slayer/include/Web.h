#pragma once
#include "Card.h"
class Web : public Card {
   public:
    Web();
    void Interact(Character*);
    std::vector<std::string> GetImage();
};