#ifndef EASEE_DISPLAY_H
#define EASEE_DISPLAY_H

#include <Arduino.h>

#include "display_types.h"

namespace easee {

class Display {
   public:
    Display();

    virtual void fillRect(const Rect& rect, const Properties& properties) = 0;
    virtual void fillScreen(const Color& color) = 0;
    virtual void fillRoundRect(const Rect& rect,
                               const Properties& properties) = 0;

    virtual void printText(const String& content, const Rect& rect,
                           const Properties& properties) = 0;

    virtual ~Display() = 0;
};

}  // namespace easee

#endif
