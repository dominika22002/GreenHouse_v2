#include "elements/leds.h"

#include <Arduino.h>

namespace{
  constexpr int FREQUENCY = 5000;
  constexpr int PWM_CHANNEL = 0;
  constexpr int RESOLUTION = 8;
}

Leds::Leds(int newPin){
  pin = newPin;
  pinMode(pin,OUTPUT);
  ledcSetup(PWM_CHANNEL, FREQUENCY, RESOLUTION); // configure LED PWM functionalitites
  ledcAttachPin(pin, PWM_CHANNEL);

  off();
}

void Leds::on(){
  digitalWrite(pin,HIGH);
}

void Leds::off(){
  digitalWrite(pin,LOW);
}

void Leds::setPWM(int value){
  ledcWrite(PWM_CHANNEL, value);
}
