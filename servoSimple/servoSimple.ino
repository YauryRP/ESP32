#define SERVO_PIN 21  
#define SERVO_CHN 0   
#define SERVO_FRQ 50  
#define SERVO_BIT 12  

// Function prototypes
void servo_set_pin(int pin);
void servo_set_angle(int angle);

void setup() {
servo_set_pin(SERVO_PIN);  
}

void loop() {
for (int i = 0; i < 180; i++) {  
    servo_set_angle(i);  
    delay(10);  // Short delay for smooth movement
}
for (int i = 180; i > 0; i--) {  
    servo_set_angle(i);  
    delay(10);  
}
}

void servo_set_pin(int pin) {

ledcAttachChannel(pin, SERVO_FRQ, SERVO_BIT, SERVO_CHN);
}

void servo_set_angle(int angle) {
if (angle > 180 || angle < 0)
    return;  
long pwm_value = map(angle, 0, 180, 103, 512);  
ledcWrite(SERVO_PIN, pwm_value);  
}