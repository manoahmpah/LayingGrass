
#ifndef COLOR_H
#define COLOR_H
#include <string>

enum class Color {
    WHITE,
    RED,
    GREEN,
    BLUE,
    MAGENTA,
    YELLOW,
    CYAN,
    ORANGE,
    PINK
};

std::string getColorCode(Color color);
std::string getColorString(const std::string_view& codeColor);

#endif
