#ifndef EASEE_COLOR_H
#define EASEE_COLOR_H

namespace easee {

class Color {
   public:
    static Color BLACK;
    static Color WHITE;
    static Color RED;
    static Color GREEN;
    static Color DARK_GREEN;
    static Color BLUE;
    static Color PURPLE;
    static Color ORANGE;
    static Color MAGENTA;

    Color(int r, int g, int b, float a = 1);

    inline int r() const { return d_r; };
    inline int g() const { return d_g; };
    inline int b() const { return d_b; };
    inline float a() const { return d_a; };

   protected:
    int d_r;
    int d_g;
    int d_b;
    float d_a;

    friend bool operator==(const Color& lhs, const Color& rhs);
};

}  // namespace easee

#endif
