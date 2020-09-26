#ifndef EASEE_RECTANGLE_H
#define EASEE_RECTANGLE_H

#include "widget.h"

namespace easee {
class Rectangle : public Widget {
   public:
    Rectangle(const Rect& rect, const Properties& properties = Properties());

    virtual void drawBackground(Display& display);
    virtual void drawForeground(Display& display);
    virtual void loop(int t);
};
}  // namespace easee

#endif
