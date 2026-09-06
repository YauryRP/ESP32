const byte adcChns[] = {14, 13, 12};
const byte ledPins[] = {38, 39, 40};    //define red, green, blue led pins
const byte pwmChns[] = {0, 1, 2};          //define the pwm channels
int colors[] = {0, 0, 0};

void setup() {
for (int i = 0; i < 3; i++) {   //setup the pwm channels,1KHz,8bit
    ledcAttachChannel(ledPins[i], 1000, 8, pwmChns[i]);
}
}

void loop() {
 for (int i = 0; i < 3; i++){
  colors[i] = map(analogRead(adcChns[i]), 0, 4096, 0, 255);
  ledcWrite(ledPins[i], 256 - colors[i]);
 }
delay(10);
}

