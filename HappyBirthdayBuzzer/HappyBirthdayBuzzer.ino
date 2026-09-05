#include <pitches.h>

#include <LiquidCrystal_I2C.h>

#include <Wire.h>

#define SDA 14                    //Define SDA pins
#define SCL 13   
#define BUZZER_PIN 9                 //Define SCL pins
const int START_COUNT = 10;      // Starting value for the countdown (in seconds)
unsigned long interval = 1000;

LiquidCrystal_I2C lcd(0x27,16,2);

int currentCount = START_COUNT;
unsigned long previousMillis = 0;
bool timerRunning = true;

int melody[] = {
  NOTE_C4, NOTE_C4, 
  NOTE_D4, NOTE_C4, NOTE_F4,
  NOTE_E4, NOTE_C4, NOTE_C4, 
  NOTE_D4, NOTE_C4, NOTE_G4,
  NOTE_F4, NOTE_C4, NOTE_C4,
  
  NOTE_C5, NOTE_A4, NOTE_F4, 
  NOTE_E4, NOTE_D4, NOTE_AS4, NOTE_AS4,
  NOTE_A4, NOTE_F4, NOTE_G4,
  NOTE_F4
};

int durations[] = {
  4, 8, 
  4, 4, 4,
  2, 4, 8, 
  4, 4, 4,
  2, 4, 8,
  
  4, 4, 4, 
  4, 4, 4, 8,
  4, 4, 4,
  2
};

void setup() {
Wire.begin(SDA, SCL);           // attach the IIC pin
if (!i2CAddrTest(0x27)) {
    lcd = LiquidCrystal_I2C(0x3F, 16, 2);
}
lcd.init();                     
lcd.backlight();               
lcd.setCursor(0,0);             
 pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
lcd.setCursor(0,1);             
   
 
 do{
countDown();
 } while(timerRunning);

int size = sizeof(durations) / sizeof(int);
  for (int note = 0; note < size; note++) {
    
    int duration = 1000 / durations[note];
    tone(BUZZER_PIN, melody[note], duration);

    int pauseBetweenNotes = duration * 1.30;
    delay(pauseBetweenNotes);
 
    noTone(BUZZER_PIN);
  }

delay(1000);
}

void countDown(){
   if (timerRunning) {
        unsigned long currentMillis = millis();

        
        if (currentMillis - previousMillis >= interval) {
            
            previousMillis = currentMillis;
            
            

            if (currentCount > 0) {
                lcd.setCursor(0,1);
                lcd.print("              ");
                lcd.setCursor(0,1);
                lcd.print( currentCount);
                lcd.println(" seconds");
                currentCount--;
            } 
              
            else if (currentCount == 0) {
              lcd.setCursor(0,1);
                lcd.print("              ");
                lcd.setCursor(0,1);
                lcd.println("Happy Birthday!!!");
                timerRunning = false; 
            }
        }
}       

}
bool i2CAddrTest(uint8_t addr) {
Wire.beginTransmission(addr);
if (Wire.endTransmission() == 0) {
    return true;
}
return false;
}