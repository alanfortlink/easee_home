#ifndef EASEE_SENSOR_CARD_H
#define EASEE_SENSOR_CARD_H

#include <Arduino.h>

#include "card.h"
#include "provider.h"
#include "text.h"

namespace {
const int k_labelSize = 1;
const int k_dataSize = 2;
const int k_labelHeight = 4;
}  // namespace

namespace easee {

template <class T>
class SensorCard : public Card {
   public:
    SensorCard<T>(const Rect& rect, const Color& color, const String& label,
                  const String& prefix = "", const String& suffix = "");
    void setup();
    void loop(int t);

    virtual void drawBackground(Display& display);
    virtual void drawForeground(Display& display);

   protected:
    String d_label;
    String d_prefix;
    String d_suffix;
};

template <class T>
SensorCard<T>::SensorCard(const Rect& rect, const Color& color,
                          const String& label, const String& prefix,
                          const String& suffix)
    : Card(rect, color), d_label(label), d_prefix(prefix), d_suffix(suffix) {}

template <class T>
void SensorCard<T>::setup() {
    Serial.begin(9600);

    d_properties = Properties(d_properties.color(), 4);
}

template <class T>
void SensorCard<T>::loop(int t) {}

template <class T>
void SensorCard<T>::drawBackground(Display& display) {
    Card(d_rect, d_properties).render(display);
}

template <class T>
void SensorCard<T>::drawForeground(Display& display) {
    const Rect baseRect = d_rect;

    String content;
    content += d_prefix;
    content += Provider<T>::instance()->get().data;
    content += d_suffix;

    Serial.println(content);

    Text(content,
         Rect(d_rect.x() + 2 * d_properties.padding(),
              d_rect.y() + 2 * d_properties.padding(), d_rect.w(), d_rect.h()),
         Properties(d_properties.color(), 0, k_dataSize, Color::WHITE))
        .render(display);

    Text(d_label,
         Rect(baseRect.x() + 2 * d_properties.padding(),
              baseRect.y() + baseRect.h() - k_labelHeight -
                  2 * d_properties.padding(),
              baseRect.w(), baseRect.h()),
         Properties(d_properties.color(), 0, k_labelSize, Color::WHITE))
        .render(display);
}

}  // namespace easee

#endif
