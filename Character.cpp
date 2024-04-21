#include "Character.h"
using namespace std;

Character::Character() {  // default constucter that sets health to 0
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
