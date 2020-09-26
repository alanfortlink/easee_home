#ifndef EASEE_CARD_H
#define EASEE_CARD_H

#include "widget.h"

namespace easee {
class Card : public Widget {
   public:
    Card(const Rect& rect, const Properties& properties);

    virtual void drawBackground(Display& display);
    virtual void drawForeground(Display& display);
    virtual void loop(int t);
};
}  // namespace easee

#endif
