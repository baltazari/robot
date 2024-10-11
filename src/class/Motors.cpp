#include <Motors.h>
Motors::Motors()
{
    motor1 = new AF_DCMotor(1);
    motor2 = new AF_DCMotor(2);
    motor3 = new AF_DCMotor(3);
    motor4 = new AF_DCMotor(4);
    speed = 100;
    speed_4 = 130;
}


void Motors::SpeedSet(int *speed)
{
    this->speed = *speed;
}

int Motors::SpeedGet()
{
    return this->speed;
}

void Motors::forward()
{
    motor1->setSpeed(this->speed);
    motor1->run(FORWARD);
    motor2->setSpeed(this->speed);
    motor2->run(FORWARD);
    motor3->setSpeed(this->speed_4);
    motor3->run(FORWARD);
    motor4->setSpeed(this->speed_4);
    motor4->run(FORWARD);
}

void Motors::backward(){
    motor1->setSpeed(this->speed);
    motor1->run(BACKWARD);
    motor2->setSpeed(this->speed);
    motor2->run(BACKWARD);
    motor3->setSpeed(this->speed_4);
    motor3->run(BACKWARD);
    motor4->setSpeed(this->speed_4);
    motor4->run(BACKWARD);
}
void Motors::right()
{
    motor1->setSpeed(this->speed);
    motor1->run(FORWARD);
    motor2->setSpeed(this->speed);
    motor2->run(FORWARD);
    motor3->setSpeed(this->speed_4);
    motor3->run(BACKWARD);
    motor4->setSpeed(this->speed_4);
    motor4->run(BACKWARD);
}
void Motors::left()
{
    motor1->setSpeed(this->speed);
    motor1->run(BACKWARD);
    motor2->setSpeed(this->speed);
    motor2->run(BACKWARD);
    motor3->setSpeed(this->speed_4);
    motor3->run(FORWARD);
    motor4->setSpeed(this->speed_4);
    motor4->run(FORWARD);
}

void Motors::stop()
{
    motor1->setSpeed(0);
    motor1->run(RELEASE);
    motor2->setSpeed(0);
    motor2->run(RELEASE);
    motor3->setSpeed(0);
    motor3->run(RELEASE);
    motor4->setSpeed(0);
    motor4->run(RELEASE);   
}