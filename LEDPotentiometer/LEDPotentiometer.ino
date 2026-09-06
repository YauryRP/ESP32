#define PIN_ANALOG_IN   1
#define PIN_LED         14
#define CHAN            0
void setup() {
ledcAttachChannel(PIN_LED, 1000, 12, CHAN);
}

void loop() {
int adcVal = analogRead(PIN_ANALOG_IN); //read adc
int pwmVal = adcVal;        // adcVal re-map to pwmVal
ledcWrite(PIN_LED, pwmVal);    // set the pulse width.
delay(10);
}