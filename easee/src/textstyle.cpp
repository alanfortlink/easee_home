#include "textstyle.h"

namespace easee {

TextStyle TextStyle::NORMAL = TextStyle();

TextStyle::TextStyle(int fontSize, Color color, Color backgroundColor)
    : d_fontSize(fontSize),
      d_color(color),
      d_backgroundColor(backgroundColor) {}

}  // namespace easee
