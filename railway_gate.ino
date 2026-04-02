#include <Servo.h>

Servo servoMain; // Define our Servo

int trigpin = 10;
int echopin = 11;
int buzzerPin = 8; // Define buzzer pin

int distance;
float duration;
float cm;

void setup()
{
   servoMain.attach(9); // servo on digital pin 9
   pinMode(trigpin, OUTPUT);
   pinMode(echopin, INPUT);
   pinMode(buzzerPin, OUTPUT); // Set buzzer as output
}

void loop()
{
  digitalWrite(trigpin, LOW);
  delay(1);

  digitalWrite(trigpin, HIGH);
  delayMicroseconds(50);
  digitalWrite(trigpin, LOW);

  duration = pulseIn(echopin, HIGH);

  cm = (duration / 68.82);
  distance = cm;

  if(distance < 10)
  {
    servoMain.write(90); // Close gate
    digitalWrite(buzzerPin, HIGH); // Buzzer ON
    delay(4000);
  }
  else
  {
    servoMain.write(0); // Open gate
    digitalWrite(buzzerPin, LOW); // Buzzer OFF
    delay(20);
  }
}
