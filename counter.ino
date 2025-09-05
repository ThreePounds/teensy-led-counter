#include <Bounce.h>

int blueButtonPin = 0;
int whiteButtonPin = 5;
int ledPins[] = {19, 20, 21, 22, 23, 24, 25, 26};

Bounce blueButton = Bounce(blueButtonPin, 5);
Bounce whiteButton = Bounce(whiteButtonPin, 5);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);
  pinMode(blueButtonPin, INPUT_PULLUP);
  pinMode(whiteButtonPin, INPUT_PULLUP);
  for (int pin : ledPins) {
    pinMode(pin, OUTPUT);
  }
}

int counter = 0;

void loop() {
  // put your main code here, to run repeatedly:
  blueButton.update();
  whiteButton.update();

  if (blueButton.fallingEdge()) {
    counter++;
    Serial.println(counter);
  }
  if (whiteButton.fallingEdge()) {
    counter--;
    Serial.println(counter);
  }

  for (int i = 0; i < (sizeof(ledPins) / sizeof(ledPins[0])); i++) {
    if (counter & (1 << i)) {
      digitalWrite(ledPins[i], HIGH);
    } else {
      digitalWrite(ledPins[i], LOW);
    }
  }
}
