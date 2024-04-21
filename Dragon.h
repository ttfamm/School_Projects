#pragma once
#include <vector>

#include "Character.h"

class Dragon : public Character {
   public:
    std::string GetName();
    std::vector<std::string> GetImage();
};