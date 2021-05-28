/*
Author:   Bhat Chaitra
Date:     28-05-2021
Title:    ESP32_TrafficLights
*/

//Initializations
#define   RED_LED_PIN       13
#define   YELLOW_LED_PIN    12
#define   GREEN_LED_PIN     14

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(RED_LED_PIN,OUTPUT);
  pinMode(YELLOW_LED_PIN,OUTPUT);
  pinMode(GREEN_LED_PIN,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:

    digitalWrite(RED_LED_PIN,HIGH);
    Serial.println("Wait for the Others to move");
    delay(2000);

    digitalWrite(RED_LED_PIN,LOW);
    digitalWrite(YELLOW_LED_PIN, HIGH);
    Serial.println("Get Set, Be ready !");
    delay(800);

    digitalWrite(YELLOW_LED_PIN,LOW);
    digitalWrite(GREEN_LED_PIN, HIGH);
    Serial.println("The road is all yours\n");
    delay(2000);

    digitalWrite(GREEN_LED_PIN,LOW);
}
