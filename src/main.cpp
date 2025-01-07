#include <Arduino.h>
#include <Servo.h>

const int trigPin = 9;
const int echoPin = 10;
const int movingLed = 11;        // LED indicating movement
const int noMovementLed = 12;    // LED indicating no movement
Servo myServo;

long duration;
int distance;
int maxDistance = 100;

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(movingLed, OUTPUT);
    pinMode(noMovementLed, OUTPUT);
    myServo.attach(6);
    myServo.write(90);                 // Barrier starts in the down position
    digitalWrite(noMovementLed, HIGH); // Green LED ON by default
    Serial.begin(9600);
}

void loop() {
    // Trigger the ultrasonic sensor
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Measure the echo duration
    duration = pulseIn(echoPin, HIGH);

    // Convert duration to distance in centimeters
    distance = duration * 0.034 / 2;

    // Print distance for debugging
    Serial.print("Distance: ");
    Serial.println(distance);

    // If an object is detected within the maxDistance range
    if (distance <= maxDistance && distance > 0) {
        myServo.write(180);                  // Raise the barrier
        digitalWrite(movingLed, HIGH);       // Red LED ON
        digitalWrite(noMovementLed, LOW);    // Green LED OFF
    } else {
        myServo.write(90);                   // Lower the barrier
        digitalWrite(movingLed, LOW);        // Red LED OFF
        digitalWrite(noMovementLed, HIGH);   // Green LED ON
    }

    delay(500); // Wait before the next measurement
}
