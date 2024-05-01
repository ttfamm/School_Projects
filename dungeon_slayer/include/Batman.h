#pragma once
#include <vector>

#include "Card.h"
#include "Character.h"
#include "Punch.h"

class Batman : public Character {
   public:
    Batman();
    std::string GetName();
    std::vector<std::string> GetImage();
    void Reward(Character*);
};
