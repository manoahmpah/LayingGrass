
#ifndef COLOR_H
#define COLOR_H
#include <string>

enum class Color {
    MAGENTA,
    RED,
    GREEN,
    BLUE,
    YELLOW,
    CYAN,
    ORANGE,
    GREEN2,
    PINK
};

std::string getColorCode(Color color);
std::string getColorString(const std::string_view& codeColor);

#endif
