#ifndef EASEE_MEMORY_H
#define EASEE_MEMORY_H

#include <Arduino.h>

namespace easee {

/**
 * @brief Wrapper over the Memory sensor.
 */
class Memory {
   public:
    struct MemoryData {
        int data;
    };

    Memory();
    ~Memory();

    /**
     * @brief reads the Memory from the sensor.
     *
     * @return current luminosity.
     */
    MemoryData getData(int t);

    /**
     * @brief Setup the luminosity sensor.
     */
    void setup();

    /**
     * @brief TODO.
     */
    void loop(int t);

   protected:
}; 
}  // namespace easee

#endif
