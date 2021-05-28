/*
Author:   Bhat Chaitra
Date:     28-05-2021
Title:    ESP32_BlinkyLED
*/

//Initializations
#define   ETERNAL_LED_PIN   13

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(ETERNAL_LED_PIN,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    digitalWrite(ETERNAL_LED_PIN, HIGH);
    Serial.println("The LED is ON !");
    delay(1000);

    digitalWrite(ETERNAL_LED_PIN, LOW);
    Serial.println("The LED is OFF!");
    delay(1000);
}
