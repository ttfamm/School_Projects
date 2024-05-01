#pragma once
#include <vector>

#include "Character.h"
#include "Fire.h"

class Dragon : public Character {
   public:
    Dragon();
    std::string GetName();
    std::vector<std::string> GetImage();
    void Reward(Character*);
};