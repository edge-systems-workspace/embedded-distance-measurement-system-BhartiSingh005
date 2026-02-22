#include <Arduino.h>
/**
 * @file main.cpp
 * @brief Embedded Distance Measurement using Ultrasonic Sensor
 * @author Bharti
 * @date 2026-02-22
 *
 * @details
 * Measures distance using HC-SR04 ultrasonic sensor
 * and displays structured output via Serial Monitor.
 */

// TODO 1:
// Define TRIG pin (Use pin 9)
#define TRIG_PIN 9

// TODO 2:
// Define ECHO pin (Use pin 10)
#define ECHO_PIN 10

// TODO 3:
// Create variable to store duration
long duration;

// TODO 4:
// Create variable to store calculated distance
int distance;

void setup() {

    // TODO 5:
    // Initialize Serial communication (9600 baud rate)
    Serial.begin(9600);

    // TODO 6:
    // Configure TRIG as OUTPUT
    pinMode(TRIG_PIN, OUTPUT);

    // TODO 7:
    // Configure ECHO as INPUT
    pinMode(ECHO_PIN, INPUT);

    // TODO 8:
    // Print system initialization message
    Serial.println("Ultrasonic Distance Measurement System");
    Serial.println("Author: Bharti");
    Serial.println("System Initialized...");
}

void loop() {

    // TODO 9:
    // Set TRIG LOW for 2 microseconds
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);

    // TODO 10:
    // Send 10 microsecond pulse on TRIG
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    // TODO 11:
    // Measure pulse duration on ECHO using pulseIn()
    duration = pulseIn(ECHO_PIN, HIGH);


    // TODO 12:
    // Calculate distance in cm
    distance = duration * 0.034 / 2;


    // TODO 13:
    // Print calculated distance
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    // Optional warning messages
    if (distance < 5) {
        Serial.println("Warning: Object too close!");
    }
    else if (distance > 200) {
        Serial.println("Warning: Object too far!");
    }

    // TODO 14:
    // Add delay (1000ms)
    delay(1000);
}