#pragma once
#include <AFMotor.h>
class Motors 
{
private:
    AF_DCMotor *motor1;
    AF_DCMotor *motor2;
    AF_DCMotor *motor3;
    AF_DCMotor *motor4;
    int speed;
    int speed_4;

public:
    Motors();
    void SpeedSet(int *speed);
    int SpeedGet();
    void forward();
    void backward();
    void right();
    void left();
    void stop();

};