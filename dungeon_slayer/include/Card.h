#pragma once
#include <vector>

#include "Character.h"

class Character;

class Card {
   public:
    Card();
    Card(std::string);
    virtual void Interact(Character*) = 0;
    void Interact(std::vector<Character*>);
    int GetCost();
    void SetCost(int);
    std::string GetName();
    void Upgrade();
    virtual std::vector<std::string> GetImage() = 0;

   private:
    int cost;
    std::string cardName;
};