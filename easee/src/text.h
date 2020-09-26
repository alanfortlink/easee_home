#ifndef EASEE_TEXT_H
#define EASEE_TEXT_H

#include <Arduino.h>
#include "widget.h"

namespace easee {
class Text : public Widget {
   public:
    Text(const String& content, const Rect& rect,
         const Properties& properties = Properties());

    virtual void drawBackground(Display& display);
    virtual void drawForeground(Display& display);
    virtual void loop(int t);

   protected:
    String d_content;
};
}  // namespace easee

#endif
