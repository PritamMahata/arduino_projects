const int soundSensorPin = A0; // Analog pin the sound sensor is connected to

void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 baud rate
}

void loop() {
  int sensorValue = analogRead(soundSensorPin); // Read the sensor value
  Serial.print("Sound Sensor Value: ");
  Serial.println(sensorValue); // Print the sensor value to the serial monitor
  delay(1000); // Delay for 1 second before reading again
}
