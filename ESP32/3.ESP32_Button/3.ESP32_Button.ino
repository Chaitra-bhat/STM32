/*
Author:   Bhat Chaitra
Date:     12-06-2021
Title:    ESP32_Button
*/

//Initilizations
#define   RED_LED_PIN       13
#define   BUTTON            12

int buttonState = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(BUTTON, INPUT);

}

void loop() {
  buttonState = digitalRead(BUTTON);
  if(buttonState == 1)
  {
    digitalWrite(RED_LED_PIN,HIGH);
  }
  else
  {
     digitalWrite(RED_LED_PIN,LOW);
  }
}
