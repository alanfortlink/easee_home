#ifndef EASEE_TEMPERATURE_H
#define EASEE_TEMPERATURE_H

#include <DHTesp.h>
#include <Arduino.h>

namespace easee {

/**
 * @brief Wrapper over the temperature and humidity sensor.
 */
class TemperatureHumidity {
   public:
    struct TemperatureData {
        // Temperature in celsius
        int data;
    };

    struct HumidityData {
        // Humidity value
        int data;
    };

    TemperatureHumidity(int port = 15);
    ~TemperatureHumidity();

    /**
     * @brief Setup the TemperatureHumidity sensor.
     */
    void setup();

    /**
     * @brief TODO.
     */
    void loop(int t);

   protected:
    int d_port;
    DHTesp d_dht;
};

}  // namespace easee

#endif
