int latchPin = 13;          // Pin connected to ST_CP of 74HC595(Pin12)
int clockPin = 14;          // Pin connected to SH_CP of 74HC595(Pin11)
int dataPin = 12;           // Pin connected to DS of 74HC595(Pin14)

void setup() 
{
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() 
{
  byte x = 0x01;    
    for (int j = 0; j < 8; j++) 
    { 
      writeTo595(LSBFIRST, x);
      x <<= 1; 
      delay(50);
    }

delay(100);
  x = 0x80;       
  for (int j = 0; j < 8; j++) 
  { 
    writeTo595(LSBFIRST, x);
    x >>= 1;
    delay(50);
  }
delay(100);
}

void writeTo595(int order, byte _data ) 
{
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, order, _data);
  digitalWrite(latchPin, HIGH);
}