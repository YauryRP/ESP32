#define PIN_LED     21         // Define the LED pin
#define TOUCH_PIN   14          // Use a valid touch pin on ESP32-S3
#define RELEASE_VAL 60000      // This threshold may need adjustment
#define PRESS_VAL   100000      // This threshold may need adjustment

bool isProcessed = false;      // Flag to track if touch event has been processed

void setup() {
Serial.begin(115200);        
pinMode(PIN_LED, OUTPUT);    
}

void loop() {
int touchValue = touchRead(TOUCH_PIN);  
  // Print touch value for debugging

if (touchValue < PRESS_VAL) {  
    if (!isProcessed) {          
    isProcessed = true;        
     Serial.println("Released!" );
    reverseGPIO(PIN_LED);      
    }
}
if (touchValue > RELEASE_VAL) {  
    if (isProcessed) {             
    isProcessed = false;         
   
     Serial.println("Touch detected!");
    }
}

delay(50);  // Short delay to prevent too frequent readings
}

void reverseGPIO(int pin) {
digitalWrite(pin, !digitalRead(pin));  
}