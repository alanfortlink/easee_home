#include "light.h"

#include "provider.h"

namespace easee {

Light::Light(int port) : d_port(port) {}

Light::~Light() {}

Light::LightData Light::getData() {
    LightData data;
    data.data = analogRead(d_port);
    return data;
}

void Light::setup() { pinMode(d_port, INPUT); }

void Light::loop(int t) { Provider<LightData>::instance()->set(getData()); }

}  // namespace easee
