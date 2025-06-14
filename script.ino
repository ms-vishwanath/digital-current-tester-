#include <ezButton.h>

ezButton mySwitch(23);
const int relay1 = 15;

void setup() {
  pinMode(relay1, OUTPUT);
  mySwitch.setDebounceTime(50);
}

void loop() {
  mySwitch.loop();

  if (mySwitch.isPressed()) {
    digitalWrite(relay1, !digitalRead(relay1));
    if (digitalRead(relay1)) {
      Serial.println("Relay: ON");
    } else {
      Serial.println("Relay: OFF");
    }
    delay(1000); // Delay to avoid multiple toggles from a single press
  }
}
