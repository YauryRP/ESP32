int dataPin = 12;
int latchPin = 13;
int clockPin = 14;
byte num[] = 
{
  0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, // 0-9
0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71  // A-F
};

void setup()
{
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop()
{
  for (int i = 0; i < 16; i++)
  {
    writeData(num[i]);
    delay(1000);
    writeData(0xff);
  }
}

void writeData(int value)
{
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, value);
  digitalWrite(latchPin, HIGH);
}