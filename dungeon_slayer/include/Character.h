#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Card.h"

class Card;

class Character {
   public:
    Character();
    void SetHealth(int);
    void SetShield(int);
    int GetHealth();
    int GetShield();
    virtual std::string GetName() = 0;
    std::vector<Card*> GetCards();
    void AddCard(Card*);
    Card* GetCardAtIndex(int);
    virtual std::vector<std::string> GetImage(void) = 0;
    virtual void Reward(Character*) = 0;

   private:
    std::string name;
    int health;
    int shield;
    std::vector<Card*> cards;
};