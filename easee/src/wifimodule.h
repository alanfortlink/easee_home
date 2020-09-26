#ifndef EASEE_WIFI_H
#define EASEE_WIFI_H

#include <Arduino.h>

namespace easee {
class WifiModule {
   public:
    struct WifiData {
        String data;
    };

    void setup();
    void loop(int t);

    WifiModule();

   protected:
};
}  // namespace easee

#endif
