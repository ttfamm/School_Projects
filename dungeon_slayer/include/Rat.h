#pragma once
#include <vector>

#include "Character.h"

class Rat : public Character {
   public:
    Rat();
    std::string GetName();
    std::vector<std::string> GetImage();
    void Reward(Character*);
};