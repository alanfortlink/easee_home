#ifndef EASEE_DISPLAY_TYPES_H
#define EASEE_DISPLAY_TYPES_H

#include "color.h"

namespace easee {

struct Rect {
   private:
    int d_x;
    int d_y;
    int d_w;
    int d_h;

   public:
    Rect(int x, int y, int w, int h) : d_x(x), d_y(y), d_w(w), d_h(h) {}
    Rect(int sz) : d_x(sz), d_y(sz), d_w(sz), d_h(sz) {}

    inline int x() const { return d_x; }
    inline int y() const { return d_y; }
    inline int w() const { return d_w; }
    inline int h() const { return d_h; }

    friend Rect operator+(const Rect& lhs, const Rect& rhs) {
        return Rect(lhs.d_x + rhs.d_x, lhs.d_y + rhs.d_y, lhs.d_w + rhs.d_w,
                    lhs.d_h + rhs.d_h);
    }
};

struct Properties {
   private:
    Color d_color;
    int d_padding;
    int d_textSize;
    Color d_bgColor;

   public:
    Properties(const Color& color = Color::BLACK, int padding = 0,
               const int& textSize = 3, const Color& bgColor = Color::BLACK)
        : d_color(color),
          d_padding(padding),
          d_textSize(textSize),
          d_bgColor(bgColor) {}

    inline const Color& color() const { return d_color; }
    inline const int& padding() const { return d_padding; }
    inline const int& textSize() const { return d_textSize; }
    inline const Color& bgColor() const { return d_bgColor; }
};

}  // namespace easee

#endif
