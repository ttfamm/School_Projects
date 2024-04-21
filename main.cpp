#include <iostream>

#include "All.h"

void display(std::vector<std::string> image) {
    for (auto line : image) {
        std::cout << line << std::endl;
    }
}

int main(int argc, char** argv) {
    Player player;
    player.SetHealth(10);
    Bash bash;
    bash.Interact(&player);
    Reaper reaper;
    Spider spider;
    Rat rat;
    Dragon dragon;
    std::cout << "Player health: " << player.GetHealth() << std::endl;
    display(bash.GetImage());
    display(reaper.GetImage());
    display(spider.GetImage());
    display(player.GetImage());
    display(rat.GetImage());
    display(dragon.GetImage());
    return 0;
}
