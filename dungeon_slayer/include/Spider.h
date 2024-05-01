#pragma once
#include <vector>

#include "Character.h"
#include "Web.h"

class Spider : public Character {
   public:
    Spider();
    std::string GetName();
    std::vector<std::string> GetImage();
    void Reward(Character*);
};