#ifndef EASEE_WIDGET_H
#define EASEE_WIDGET_H

#include "display_types.h"
#include "display.h"

namespace easee {

class Widget {
   public:
    Widget(const Rect& rect, const Properties& properties = Properties());
    virtual ~Widget();

    void render(Display& display);

    virtual void drawBackground(Display& display) = 0;
    virtual void drawForeground(Display& display) = 0;

    virtual void loop(int t) {}

    void invalidate() { d_invalidated = true; }
    inline bool invalidated() { return d_invalidated; };

   protected:
    Rect d_rect;
    Properties d_properties;;

    bool d_invalidated;
    bool d_isFirstTime;
};

}  // namespace easee

#endif
