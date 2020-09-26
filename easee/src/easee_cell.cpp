#include "easee_cell.h"

#include <Arduino.h>
#include <HTTPClient.h>
#include <WiFi.h>

namespace easee {

namespace {

const int k_displayWidth = 126;
const int k_displayHeight = 126;

const int k_cardWidth = k_displayWidth / 2;
const int k_cardHeight = k_displayHeight / 2.0;

}  // namespace

EaseeCell::EaseeCell()
    : d_oneInchDisplay(),
      d_temperatureCard(Rect(0, 0, k_cardWidth, k_cardHeight), Color::BLUE,
                        "Temp.", "", "C"),
      d_humidityCard(Rect(k_cardWidth, 0, k_cardWidth, k_cardHeight),
                     Color::RED, "Humidity"),
      d_lightCard(Rect(0, k_cardHeight, k_cardWidth, k_cardHeight),
                  Color::MAGENTA, "Lumin."),
      d_memoryCard(Rect(k_cardWidth, k_cardHeight, k_cardWidth, k_cardHeight),
                   Color::BLACK, "Memory", ">", "K"),
      d_temperatureHumidity(),
      d_light(),
      d_memory(),
      d_wifiModule()

{}

void EaseeCell::setup() {
    d_oneInchDisplay.setup();
    d_temperatureCard.setup();
    d_humidityCard.setup();
    d_lightCard.setup();
    d_memoryCard.setup();
    d_temperatureHumidity.setup();
    d_light.setup();
    d_memory.setup();
    d_wifiModule.setup();

    // pinMode(2, OUTPUT);
    d_oneInchDisplay.fillScreen(Color::WHITE);
}

void EaseeCell::loop(int t) {
    // digitalWrite(2, HIGH);
    // delay(500);
    // digitalWrite(2, LOW);
    // delay(500);

    d_oneInchDisplay.loop(t);
    d_temperatureCard.loop(t);

    d_humidityCard.loop(t);
    d_lightCard.loop(t);
    d_memoryCard.loop(t);
    d_temperatureHumidity.loop(t);
    d_light.loop(t);
    d_memory.loop(t);
    d_wifiModule.loop(t);

    d_temperatureCard.render(d_oneInchDisplay);
    d_humidityCard.render(d_oneInchDisplay);
    d_lightCard.render(d_oneInchDisplay);
    d_memoryCard.render(d_oneInchDisplay);
}

}  // namespace easee
