#include <Arduino.h>
#include "CandyGrabber.h"

CandyGrabber candyGrabber;

void setup() {
    candyGrabber.setup();
}

void loop() {
    candyGrabber.loop();
}
