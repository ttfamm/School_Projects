#pragma once
#include <vector>

#include "Character.h"

class Reaper : public Character {
   public:
    std::string GetName();
    std::vector<std::string> GetImage();
};