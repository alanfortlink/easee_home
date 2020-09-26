#include "widget.h"

namespace easee {

Widget::Widget(const Rect& rect, const Properties& properties)
    : d_rect(rect),
      d_properties(properties),
      d_invalidated(true),
      d_isFirstTime(true) {}

void Widget::render(Display& display) {
    if (invalidated()) {
        d_invalidated = false;
        drawBackground(display);
    }

    drawForeground(display);
    d_isFirstTime = false;
}

Widget::~Widget() {}

}  // namespace easee
