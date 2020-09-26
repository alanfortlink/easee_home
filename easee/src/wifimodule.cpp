#include "wifimodule.h"

#include "provider.h"

namespace {
int st = 0;
}  // namespace

namespace easee {

WifiModule::WifiModule() {}

void WifiModule::setup() {}

void WifiModule::loop(int t) {
    // Provider<WifiData>::instance()->set(WifiData());
}

}  // namespace easee
