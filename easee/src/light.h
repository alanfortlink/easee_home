#ifndef EASEE_LIGHT_H
#define EASEE_LIGHT_H

#include <Arduino.h>

namespace easee {

/**
 * @brief Wrapper over the Light sensor.
 */
class Light {
   public:
    struct LightData {
        int data;
    };

    Light(int port = 34);
    ~Light();

    /**
     * @brief reads the Light from the sensor.
     *
     * @return current luminosity.
     */
    LightData getData();

    /**
     * @brief Setup the luminosity sensor.
     */
    void setup();

    /**
     * @brief TODO.
     */
    void loop(int t);

   protected:
    int d_port;
};

}  // namespace easee

#endif
