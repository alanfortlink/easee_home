#include "temperature_humidity.h"

#include "provider.h"

namespace easee {

TemperatureHumidity::TemperatureHumidity(int port) : d_port(port), d_dht() {}

TemperatureHumidity::~TemperatureHumidity() {}

void TemperatureHumidity::setup() { d_dht.setup(d_port, DHTesp::DHT11); }

void TemperatureHumidity::loop(int t) {
    float humidity = d_dht.getHumidity();
    float temperature = d_dht.getTemperature();

    if (d_dht.getStatusString() != "OK") return;

    HumidityData humidityData;
    humidityData.data = humidity;

    TemperatureData temperatureData;
    temperatureData.data = temperature;

    Provider<TemperatureData>::instance()->set(temperatureData);
    Provider<HumidityData>::instance()->set(humidityData);
}

}  // namespace easee
