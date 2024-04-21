#pragma once
#include <vector>

#include "Character.h"

class Card {
   public:
    Card();
    Card(std::string);
    virtual void Interact(Character*) = 0;
    void Interact(Character*[], int);
    int GetCost();
    void SetCost(int);
    void SetModifier(int);
    int GetModifier();
    std::string GetName();
    void Upgrade();
    virtual std::vector<std::string> GetImage() = 0;

   private:
    int cost;
    int modifier;
    std::string cardName;
};