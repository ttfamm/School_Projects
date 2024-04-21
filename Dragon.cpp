#include "Dragon.h"

std::string Dragon::GetName() {
    return "dragon";
}

std::vector<std::string> Dragon::GetImage() {
    return std::vector<std::string>{
        "============================================",
        "|   <>=======()                            |",
        "|  (/\\___   /|\\          ()==========<>_   |",
        "|        \\_/ | \\        //|\\   ______/ \\)  |",
        "|          \\_|  \\      // | \\_/            |",
        "|           \\|\\/|\\_   //  /\\/              |",
        "|            (oo)\\ \\_//  /                 |",
        "|            //_/\\_\\/ /  |                 |",
        "|            //_/\\_\\/ /  |                 |",
        "|          @@/  |=\\  \\  |                  |",
        "|               \\_=\\_ \\ |                  |",
        "|                  \\==\\ \\|\\_               |",
        "|               __(\\===\\(  )\\              |",
        "|              (((~) __(_/   |             |",
        "|                   (((~) \\  /             | ",
        "|                   ______/ /              |",
        "|                   '------'               |",
        "============================================",
    };
}