#include "Rat.h"

std::string Rat::GetName() {
    return "rat";
}

std::vector<std::string> Rat::GetImage() {
    return std::vector<std::string>{
        "============================",
        "|                          |",
        "|     (`-()_.-=-.          |",
        "|      /66  ,  ,  \\        |",
        "|    =(o_/=//_(   /======` |",
        "|       ~''`  ~''~~`       |",
        "============================",
    };
}