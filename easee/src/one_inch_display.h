#ifndef EASEE_ONE_INCH_DISPLAY_H
#define EASEE_ONE_INCH_DISPLAY_H

#include <XTronical_ST7735.h>  // Hardware-specific library

#include "display.h"
#include "display_types.h"

namespace easee {

class OneInchDisplay : public Display {
   public:
    OneInchDisplay();
    virtual ~OneInchDisplay();

    void setup();
    void loop(int t);

    virtual void fillRect(const Rect& rect, const Properties& properties);
    virtual void fillScreen(const Color& color);
    virtual void fillRoundRect(const Rect& rect, const Properties& properties);

    virtual void printText(const String& content, const Rect& rect,
                           const Properties& properties);

   protected:
    Adafruit_ST7735 d_display;
};

}  // namespace easee

#endif
