#pragma once
#include <vector>

#include "Card.h"
#include "Character.h"
class Player : public Character {
   public:
    Player();
    std::string GetName();
    std::vector<Card*> DrawFromPile();
    void PutIntoDiscardPile(Card*);
    void Shuffle();
    std::vector<std::string> GetImage();

   private:
    std::vector<Card*> drawPile;
    std::vector<Card*> discardPile;
};
