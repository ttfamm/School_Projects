#include "Card.h"

Card::Card() {
}

Card::Card(std::string name) {  // overloaded constructer that sets modifier to 0 and cardName to name
    cardName = name;
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

void Card::Upgrade() {
    cardName += "+";
}
// multiple interactions with characters
void Card::Interact(std::vector<Character*> characters) {
    for (int i = 0; i < characters.size(); i++) {
        Interact(characters[i]);
    }
}
