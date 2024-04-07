// Pin assignments
const int soundSensorPin = A0; // Connect sound sensor to analog pin A0
const int builtInLEDPin = 13;  // Built-in LED is connected to pin 13

// Variables to store sound sensor readings and clap count
int soundSensorValue;
int clapCount = 0;
int threshold = 500; // Adjust this threshold according to your environment

// Variable to store time of last clap
unsigned long lastClapTime = 0;

void setup() {
  pinMode(soundSensorPin, INPUT);    // Set sound sensor pin as input
  pinMode(builtInLEDPin, OUTPUT);    // Set built-in LED pin as output
  
  // Initialize built-in LED to off state
  digitalWrite(builtInLEDPin, LOW);
}

void loop() {
  soundSensorValue = analogRead(soundSensorPin);
  if (soundSensorValue > threshold) {
    if (millis() - lastClapTime > 200) {
      clapCount++;
      lastClapTime = millis();
    }
  }
  if (clapCount == 1) {
    digitalWrite(builtInLEDPin, HIGH);
  }
  else if (clapCount == 2) {
    digitalWrite(builtInLEDPin, LOW);
  }
  if (clapCount > 2) {
    clapCount = 0;
  }
}
