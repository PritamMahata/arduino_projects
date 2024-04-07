#include <Servo.h>
Servo myservo;
int pos = 0;
int soundSensor = 2;
int LED = 4;
boolean LEDStatus = false;
void setup()
{
    myservo.attach(9);
    pinMode(soundSensor, INPUT);
    pinMode(LED, OUTPUT);
}
void loop()
{
    int SensorData = digitalRead(soundSensor);
    if (SensorData == 1)
    {
        if (LEDStatus == false)
        {
            LEDStatus = true;
            digitalWrite(LED, HIGH);
            for (pos = 0; pos <= 180; pos += 1)
            { // goes from 0 degrees to 180 degrees
                // in steps of 1 degree
                myservo.write(pos); // tell servo to go to position in variable 'pos'
                delay(15);          // waits 15ms for the servo to reach the position
            }
        }
        else
        {
            LEDStatus = false;
            digitalWrite(LED, LOW);
            for (pos = 180; pos >= 0; pos -= 1)
            {                       // goes from 180 degrees to 0 degrees
                myservo.write(pos); // tell servo to go to position in variable 'pos'
                delay(15);          // waits 15ms for the servo to reach the position
            }
        }
    }
}
