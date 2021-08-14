#include "AnalogButton.h"

AnalogButton btn1(0,300);
AnalogButton btn2(450,600);
AnalogButton btn3(600,750);
AnalogButton btn4(750,850);

void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT_PULLUP);
  btn1.setOnDown([]{
    Serial.println("1 Da nhan");
  });
  btn1.setOnPress([](uint32_t time){
    Serial.print("1 Da nhan: ");
    Serial.println(time);
  });
  btn1.setOnUp([](uint32_t time){
    Serial.print("1 Da tha: ");
    Serial.println(time);
  });

  btn2.setOnDown([]{
    Serial.println("2 Da nhan");
  });
  btn2.setOnPress([](uint32_t time){
    Serial.print("2 Da nhan: ");
    Serial.println(time);
  });
  btn2.setOnUp([](uint32_t time){
    Serial.print("2 Da tha: ");
    Serial.println(time);
  });

  btn3.setOnDown([]{
    Serial.println("3 Da nhan");
  });
  btn3.setOnPress([](uint32_t time){
    Serial.print("3 Da nhan: ");
    Serial.println(time);
  });
  btn3.setOnUp([](uint32_t time){
    Serial.print("3 Da tha: ");
    Serial.println(time);
  });

  btn4.setOnDown([]{
    Serial.println("4 Da nhan");
  });
  btn4.setOnPress([](uint32_t time){
    Serial.print("4 Da nhan: ");
    Serial.println(time);
  });
  btn4.setOnUp([](uint32_t time){
    Serial.print("4 Da tha: ");
    Serial.println(time);
  });
}

void loop() {
  uint16_t read = analogRead(A0);
  btn1.loop(read);
  btn2.loop(read);
  btn3.loop(read);
  btn4.loop(read);
}
