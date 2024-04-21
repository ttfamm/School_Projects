#pragma once
#include <iostream>
#include <string>

class Character {
   public:
    Character();
    void SetHealth(int);
    void SetShield(int);
    int GetHealth();
    int GetShield();
    virtual std::string GetName() = 0;

   private:
    std::string name;
    int health;
    int shield;
};