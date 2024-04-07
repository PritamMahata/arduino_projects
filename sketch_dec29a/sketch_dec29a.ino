const int OUT_PIN = 8;
void setup() {
  Serial.begin(9600);

}

void loop() {
  Serial.println(digitalRead(OUT_PIN));
}
