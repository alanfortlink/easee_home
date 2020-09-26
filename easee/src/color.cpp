#include "color.h"

namespace easee {

Color Color::BLACK = Color(0, 0, 0);
Color Color::WHITE = Color(255, 255, 255);
Color Color::RED = Color(255, 0, 0);
Color Color::GREEN = Color(0, 255, 0);
Color Color::DARK_GREEN = Color(0, 120, 0);
Color Color::BLUE = Color(0, 0, 255);
Color Color::PURPLE = Color(128, 0, 128);
Color Color::ORANGE = Color(255, 140, 0);
Color Color::MAGENTA = Color(255, 0, 255);

Color::Color(int r, int g, int b, float a) : d_r(r), d_g(g), d_b(b), d_a(a) {}

bool operator==(const Color& lhs, const Color& rhs) {
    return lhs.d_r == rhs.d_r && lhs.d_g == rhs.d_g && lhs.d_b == rhs.d_b &&
           lhs.d_a == rhs.d_a;
}

}  // namespace easee
