#include "Card.h"

Card::Card() {
    modifier = 0;  // default constructer that sets modifier to 0
}

Card::Card(std::string name) {  // overloaded constructer that sets modifier to 0 and cardName to name
    cardName = name;
    modifier = 0;
}

std::string Card::GetName() {
    return cardName;
}

void Card::SetCost(int c) {
    cost = c;
}

int Card::GetCost() {
    return cost;
}

void Card::SetModifier(int m) {
    modifier = m;
}

int Card::GetModifier() {
    return modifier;
}
// upgrades the card (Bash -> Bash+)
void Card::Upgrade() {
    cardName += "+";
}
// multiple interactions with characters
void Card::Interact(Character* characters[], int numCharacters) {
    for (int i = 0; i < numCharacters; i++) {
        Interact(characters[i]);
    }
}
