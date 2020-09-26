#include "rectangle.h"

namespace easee {

Rectangle::Rectangle(const Rect& rect, const Properties& properties)
    : Widget(rect, properties) {}

void Rectangle::drawBackground(Display& display) {}

void Rectangle::drawForeground(Display& display) {
    display.fillRect(d_rect, d_properties);
}

void Rectangle::loop(int t) {}

}  // namespace easee
