#pragma once
#include <Servo.h>
#include <Motors.h>
#include <Arduino.h>
#include <Distance_sensor.h>


class Robot : public Motors, public Distance_sensor
{
private:
    Servo My_servo;
    int servo_pin;
    int servo_position;
    int angle[3];
    int new_distance[3];
    int car_length;
    int car_width;
    int old_distance[3];

public:
    Robot();
    // ~Robot();
    void Servo_move();  
    void servo_init();
    double pithagor();
    void old_distance_set();
    bool check_old_distance();

};