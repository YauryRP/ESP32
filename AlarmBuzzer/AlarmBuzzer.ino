#define PIN_BUZZER 14
#define PIN_BUTTON 21
#define CHN 0

void setup() {
pinMode(PIN_BUZZER, OUTPUT);
pinMode(PIN_BUTTON, INPUT);
ledcAttachChannel(PIN_BUZZER, 2000, 10, CHN);  //attach the led pin to pwm channel
ledcWriteTone(PIN_BUZZER, 2000);        //Sound at 2KHz for 0.3 seconds
delay(300);
}

void loop() {
if (digitalRead(PIN_BUTTON) == LOW) {
 alarm();
}else{
    ledcWriteTone(PIN_BUZZER, 0);
}
delay(10);
}

void alarm() {
for ( int frq = 500; frq <= 2500; frq += 25){
  ledcWriteTone(PIN_BUZZER,frq);
  delay(10);
}
for (int frq = 2500; frq >= 500; frq -= 25){
  ledcWriteTone(PIN_BUZZER, frq);
  delay(10);
}
}