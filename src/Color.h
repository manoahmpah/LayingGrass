
#ifndef COLOR_H
#define COLOR_H
#include <string>

enum class Color {
    RESET = 0,
    RED,
    GREEN,
    BLUE,
    YELLOW,
    CYAN,
    MAGENTA,
    ORANGE,
    PURPLE,
    PINK
};

std::string getColorCode(Color color);
std::string getColorString(const std::string& codeColor);

#endif
