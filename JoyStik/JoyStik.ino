int xyPins[] = { 14, 13 }; // x, y,
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
int xVAl = analogRead(xyPins[0]);
int yVal = analogRead(xyPins[1]);
Serial.printf("X,Y: %d, \t%d\n", xVAl, yVal);
delay(500);
}
