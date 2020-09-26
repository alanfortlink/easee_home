
#include "card.h"

namespace easee {

Card::Card(const Rect& rect, const Properties& properties)
    : Widget(rect, properties) {}

void Card::drawBackground(Display& display) {
    display.fillRoundRect(d_rect, d_properties);
    display.fillRoundRect(
        d_rect + Rect(1, 1, -3, -3),
        Properties(Color::WHITE, d_properties.padding(),
                   d_properties.textSize(), d_properties.color()));
}

void Card::drawForeground(Display& display) {}

void Card::loop(int t) {}

}  // namespace easee
