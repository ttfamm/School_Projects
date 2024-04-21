#include "Spider.h"

std::string Spider::GetName() {
    return "reaper";
}

std::vector<std::string> Spider::GetImage() {
    return std::vector<std::string>{
        "=================",
        "|     / _ \\     |",
        "|   \\_\\(_)/_/   |",
        "|    _//o\\\\_    |",
        "|     /   \\     |",
        "================="};
}