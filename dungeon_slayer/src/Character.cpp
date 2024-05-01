#include "Character.h"
using namespace std;

Character::Character() {
    health = 0;
}
void Character::SetHealth(int h) {
    health = h;
}
void Character::SetShield(int s) {
    shield = s;
}
int Character::GetHealth() {
    return health;
}
int Character::GetShield() {
    return shield;
}
std::vector<Card*> Character::GetCards() {
    return cards;
}
void Character::AddCard(Card* card) {
    cards.push_back(card);
}
Card* Character::GetCardAtIndex(int index) {
    if (index >= cards.size()) {
        return nullptr;
    }
    return cards.at(index);
}
