#pragma once
#include <vector>

#include "Character.h"
#include "Slash.h"

class Reaper : public Character {
   public:
    Reaper();
    std::string GetName();
    std::vector<std::string> GetImage();
    void Reward(Character*);
};