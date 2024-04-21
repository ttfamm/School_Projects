#pragma once
#include <vector>

#include "Character.h"

class Rat : public Character {
   public:
    std::string GetName();
    std::vector<std::string> GetImage();
};