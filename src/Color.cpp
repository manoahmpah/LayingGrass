#include "Color.h"

#include <string>

std::string getColorCode(const Color color) {
    switch (color) {
        case Color::RESET:   return "\033[0m";
        case Color::RED:     return "\033[31m";
        case Color::GREEN:   return "\033[32m";
        case Color::BLUE:    return "\033[34m";
        case Color::YELLOW:  return "\033[33m";
        case Color::CYAN:    return "\033[36m";
        case Color::MAGENTA: return "\033[35m";
        case Color::ORANGE:  return "\033[38;5;214m";
        case Color::PURPLE:  return "\033[35m";
        case Color::PINK:    return "\033[38;5;13m";
        default:             return "\033[0m";
    }
}

std::string getColorString(const std::string& codeColor) {
    if (codeColor == "\033[0m")         return "RESET";
    else if (codeColor == "\033[31m")   return "RED";
    else if (codeColor == "\033[32m")   return "GREEN";
    else if (codeColor == "\033[34m")   return "BLUE";
    else if (codeColor == "\033[33m")   return "YELLOW";
    else if (codeColor == "\033[36m")   return "CYAN";
    else if (codeColor == "\033[35m")   return "MAGENTA";
    else if (codeColor == "\033[38;5;214m") return "ORANGE";
    else if (codeColor == "\033[38;5;13m")  return "PINK";
    else return "RESET";
}
