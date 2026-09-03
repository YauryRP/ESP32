String inputString = "";      
bool stringComplete = false; 
void setup() {
Serial.begin(115200);
Serial.println("ESP32S3 initialization completed!");
Serial.println(String("\nESP32S3 initialization completed!\r\n")
                + String("Please input some characters,\r\n")
                + String("select \"Newline\" below and Ctrl + Enter to send message to ESP32S3. \r\n"));
}

void loop() {
Serial.printf("Running time : %.1f s\r\n", millis() / 1000.0f);
if (Serial.available()) {         // judge whether data has been received
    char inChar = Serial.read();         // read one character
    inputString += inChar;
    if (inChar == '\n') {
    stringComplete = true;
    }
}
if (stringComplete) {
    Serial.printf("inputString: %s \r\n", inputString);
    inputString = "";
    stringComplete = false;
}
delay(1000);
}