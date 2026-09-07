#define trigPin 13 
#define echoPin 14 
#define MAX_DISTANCE 700 

float timeOut = MAX_DISTANCE * 60;
int soundVelocity = 340; 
void setup() {
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT); 
Serial.begin(115200);   
}

void loop() {
delay(100); 
Serial.printf("Distance: ");
Serial.print(getSonar()); 
Serial.println("cm");
}

float getSonar() {
unsigned long pingTime;
float distance;

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

pingTime = pulseIn(echoPin, HIGH, timeOut);

distance = (float)pingTime * soundVelocity / 2 / 10000;
return distance; 
}