#ifndef EASEE_EASEE_CELL_H
#define EASEE_EASEE_CELL_H

#include "temperature_humidity.h"
#include "light.h"
#include "memory.h"
#include "one_inch_display.h"
#include "sensor_card.h"
#include "wifimodule.h"

namespace easee {

class EaseeCell {
   public:
    EaseeCell();

    void setup();
    void loop(int t);

   protected:
    OneInchDisplay d_oneInchDisplay;

    SensorCard<TemperatureHumidity::TemperatureData> d_temperatureCard;
    SensorCard<TemperatureHumidity::HumidityData> d_humidityCard;
    SensorCard<Light::LightData> d_lightCard;
    SensorCard<Memory::MemoryData> d_memoryCard;

    TemperatureHumidity d_temperatureHumidity;
    Light d_light;
    Memory d_memory;
    WifiModule d_wifiModule;
};

}  // namespace easee

#endif
