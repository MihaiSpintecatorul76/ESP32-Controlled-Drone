#include <Arduino.h>


const int esc1Pin = 2;
const int esc2Pin = 3;
const int esc3Pin = 0;
const int esc4Pin = 1;


const int freq = 50;          
const int ledChannel1 = 0;
const int ledChannel2 = 1;
const int ledChannel3 = 2;
const int ledChannel4 = 3;
const int resolution = 16;    


void ledcAnalogWrite(uint8_t channel, uint32_t value, uint32_t valueMax = 65535) {
  uint32_t duty = (value * ((1 << resolution) - 1)) / valueMax; 
  ledcWrite(channel, duty);
}


uint32_t pulseWidthToPWM(int pulseWidth) {
  
  return (uint32_t)((pulseWidth / 20000.0) * 65535);
}

void setup() {
  Serial.begin(115200);



ledcAttach(esc1Pin, freq, resolution);
  ledcAttach(esc2Pin, freq, resolution);
  ledcAttach(esc3Pin, freq, resolution);
  ledcAttach(esc4Pin, freq, resolution);


  ledcAnalogWrite(ledChannel1, pulseWidthToPWM(1000));
  ledcAnalogWrite(ledChannel2, pulseWidthToPWM(1000));
  ledcAnalogWrite(ledChannel3, pulseWidthToPWM(1000));
  ledcAnalogWrite(ledChannel4, pulseWidthToPWM(1000));

 
  delay(2000); 
}

void loop() {
 
  for (int pw = 1000; pw <= 2000; pw += 100) {
    ledcAnalogWrite(ledChannel1, pulseWidthToPWM(pw));
    ledcAnalogWrite(ledChannel2, pulseWidthToPWM(pw));
    ledcAnalogWrite(ledChannel3, pulseWidthToPWM(pw));
    ledcAnalogWrite(ledChannel4, pulseWidthToPWM(pw));
    Serial.print("PWM: "); Serial.println(pw);
    delay(500);
  }


  for (int pw = 2000; pw >= 1000; pw -= 100) {
    ledcAnalogWrite(ledChannel1, pulseWidthToPWM(pw));
    ledcAnalogWrite(ledChannel2, pulseWidthToPWM(pw));
    ledcAnalogWrite(ledChannel3, pulseWidthToPWM(pw));
    ledcAnalogWrite(ledChannel4, pulseWidthToPWM(pw));
    Serial.print("PWM: "); Serial.println(pw);
    delay(500);
  }
}
