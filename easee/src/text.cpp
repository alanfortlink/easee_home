#include "text.h"

namespace easee {

Text::Text(const String& content, const Rect& rect,
           const Properties& properties)
    : Widget(rect, properties), d_content(content) {}

void Text::drawBackground(Display& display) {}

void Text::drawForeground(Display& display) {
    display.printText(d_content, d_rect, d_properties);
}

void Text::loop(int t) {}

}  // namespace easee
