#include <Arduino.h>
#include <Servo.h>

const int trigPin = 9;
const int echoPin = 10;
const int movingLed = 11;
const int noMovementLed = 12;
Servo myServo;

long duration;
int distance;
int maxDistance = 20;

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(movingLed, OUTPUT);
    pinMode(noMovementLed, OUTPUT);
    myServo.attach(6);
    myServo.write(90);
    digitalWrite(noMovementLed, HIGH);
    Serial.begin(9600);
}

void loop() {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);

    distance = duration * 0.034 / 2;

    Serial.print("Distance: ");
    Serial.println(distance);


    if (distance <= maxDistance && distance > 0) {
        myServo.write(180);
        digitalWrite(movingLed, HIGH);
        digitalWrite(noMovementLed, LOW);
    } else {
        myServo.write(90);
        digitalWrite(movingLed, LOW);
        digitalWrite(noMovementLed, HIGH);
    }

    delay(4000);
}
