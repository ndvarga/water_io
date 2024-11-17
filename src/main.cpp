#include "AdafruitSTEMMA.hpp"
#include <Arduino.h>
#include <Adafruit_seesaw.h>
#include <string.h>
#define STEMMA_ADDR 0x36
#define STEMMA_TEMP_PIN 0
#define INTERVAL 3600000
Adafruit_seesaw ss;
unsigned long lastCheckTime = 0;

void setup() {
    Serial.begin(115200);
    
    if (!ss.begin(STEMMA_ADDR)) {
        Serial.println("ERROR! seesaw not found");
        while(1) delay(1);
    } 
    else {
        Serial.print("seesaw started! version: ");
        Serial.println(ss.getVersion(), HEX);
    }
}

void loop() {
    unsigned long currentTime = millis();
    if (currentTime - lastCheckTime >= INTERNAL)
    {        

        float tempC = ss.getTemp();
        uint16_t capread = ss.touchRead(STEMMA_TEMP_PIN);

        Serial.print(F("Temperature: ")); Serial.print(tempC); Serial.println(F("*C"));
        Serial.print("Capacitive: "); Serial.println(capread);
    }
}   