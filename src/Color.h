
#ifndef COLOR_H
#define COLOR_H
#include <string>

/**
 * @brief Enumeration for the color of the players.
 */
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

/**
 * @brief Gets the color code of the given color.
 * \param color Color to get the code.
 * \return Color code.
 */
std::string getColorCode(Color color);

/**
 * \brief Gets the color string of the given color.
 * \param codeColor Color to get the string.
 * \return Color string.
 */
std::string getColorString(const std::string_view& codeColor);

#endif
