#include "src/easee_cell.h"

namespace {
easee::EaseeCell app;
}

void setup() { app.setup(); }

void loop() { app.loop(millis()); }
