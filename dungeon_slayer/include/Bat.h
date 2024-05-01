#pragma once
#include <vector>

#include "Character.h"
#include "Strike.h"

class Bat : public Character {
   public:
    Bat();
    std::string GetName();
    std::vector<std::string> GetImage();
    void Reward(Character*);
};