#include <Distance_sensor.h>
#include <Arduino.h>

// long duration;
// int distance;

// int actual_distance()
// {
//     digitalWrite(trigPin, LOW);
//     delayMicroseconds(2);
//     digitalWrite(trigPin, HIGH);
//     delayMicroseconds(10);
//     digitalWrite(trigPin, LOW);
//     duration = pulseIn(echoPin, HIGH);
//     distance = duration * 0.034 / 2;

//     return distance;
// }
// void Ultra_sensor_init()
// {
//     pinMode(trigPin, OUTPUT);
//     pinMode(echoPin, INPUT);
// }

Distance_sensor::Distance_sensor() {
    this->trigPin = A0;
    this->echoPin = A1;
    this->min_distance = 20;
    pinMode(this->trigPin, OUTPUT);
    pinMode(this->echoPin, INPUT);
}

// Distance_sensor::~Distance_sensor()
// {
//     delete &this->trigPin;
//     delete &this->echoPin;
//     delete &this->min_distance;
//     delete &this->duration;
//     delete &this->distance;
// }

int Distance_sensor::Get_min_distance() {
    return this->min_distance;
}

int Distance_sensor::Actual_distance() {
    digitalWrite(this->trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(this->trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(this->trigPin, LOW);
    this->duration = pulseIn(this->echoPin, HIGH);
    this->distance = this->duration * 0.034 / 2;
    return this->distance;
}


