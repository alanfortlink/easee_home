#include "one_inch_display.h"

namespace {
int getColor(const easee::Color& color) {
    if (color == easee::Color::BLACK) return ST7735_BLACK;
    if (color == easee::Color::BLUE) return ST7735_BLUE;
    if (color == easee::Color::RED) return ST7735_RED;
    if (color == easee::Color::WHITE) return ST7735_WHITE;
    if (color == easee::Color::GREEN) return ST7735_GREEN;
    if (color == easee::Color::MAGENTA) return ST7735_MAGENTA;

    return ST7735_BLACK;
}
}  // namespace

namespace easee {

OneInchDisplay::OneInchDisplay() : d_display(5, 2, 4) {}

OneInchDisplay::~OneInchDisplay() {}

void OneInchDisplay::setup() {
    d_display.init();
    // d_display.invertDisplay(true);
    d_display.setRotation(3);
}

void OneInchDisplay::loop(int t) {}

void OneInchDisplay::fillScreen(const Color& color) {
    d_display.fillScreen(getColor(color));
}

void OneInchDisplay::fillRect(const Rect& rect, const Properties& properties) {
    d_display.fillRect(
        rect.x() + properties.padding(), rect.y() + properties.padding(),
        rect.w() - properties.padding(), rect.h() - properties.padding(),
        getColor(properties.color()));
}

void OneInchDisplay::fillRoundRect(const Rect& rect,
                                   const Properties& properties) {
    d_display.fillRoundRect(
        rect.x() + properties.padding(), rect.y() + properties.padding(),
        rect.w() - properties.padding(), rect.h() - properties.padding(), 3,
        getColor(properties.color()));
}  // namespace easee

void OneInchDisplay::printText(const String& content, const Rect& rect,
                               const Properties& properties) {
    d_display.setTextColor(getColor(properties.color()),
                           getColor(properties.bgColor()));
    d_display.setCursor(rect.x(), rect.y());
    d_display.setTextSize(properties.textSize());
    d_display.print(content);
}

}  // namespace easee
