#include <Robot.h>

Robot::Robot()
    : angle{0, 180, 90}, new_distance{0, 0, 0} {
    this->servo_pin = 10;
    this->servo_position = 90;
    this->car_length = 30;
    this->car_width = 8;
}


void Robot::Servo_move() {
    old_distance_set();
    // Serial.println();
    if (Distance_sensor::Actual_distance() < Distance_sensor::Get_min_distance() || check_old_distance() == true) {
        Motors::stop();
        for (int i = 0; i < 3; i++) {
            new_distance[i] = Distance_sensor::Actual_distance();
            My_servo.write(angle[i]);
            delay(1000);
            Serial.print("Distance ");
            Serial.print(i);
            Serial.print(" :");
            Serial.println(new_distance[i]);
            Serial.print("old Distance  ");
            Serial.print(i);
            Serial.print(" :");
            Serial.println(this->old_distance[i]);
            Serial.println(check_old_distance());
        }
        if ((new_distance[1] > new_distance[0] && new_distance[1] > new_distance[2]) || (
                check_old_distance() == true)) {
            while (Distance_sensor::Actual_distance() < new_distance[1]) {
                Motors::right();
            }
        } else if ((new_distance[2] > new_distance[0] && new_distance[2] > new_distance[1]) || (
                       check_old_distance() == true)) {
            while (Distance_sensor::Actual_distance() < new_distance[2]) {
                Motors::left();
            }
        } else if ((car_length >= new_distance[1] + new_distance[2]) && new_distance[0] <
                   Distance_sensor::Get_min_distance()) {
            for (int i = 0; i < 3; i++) {
                new_distance[i] = Distance_sensor::Actual_distance();
                My_servo.write(angle[i]);
                while (car_length >= new_distance[1] + new_distance[2]) {
                    Motors::backward();
                }
            }
        }
    } else {
        Motors::forward();
    }
}

void Robot::servo_init() {
    My_servo.attach(servo_pin);
}

double Robot::pithagor() {
    double num1 = Distance_sensor::Actual_distance() * Distance_sensor::Actual_distance();
    double num2 = car_width * car_width;
    double num3 = sqrt(num1 + num2);
    num2 = sqrt(num3 * num3 - num1);
    return num2;
}

void Robot::old_distance_set() {
    for (int i = 0; i < 3; i++) {
        this->old_distance[i] = Distance_sensor::Actual_distance();
        delay(50);
    }
}

bool Robot::check_old_distance() {
    if (this->old_distance[0] == old_distance[1] && this->old_distance[0] == old_distance[2] && this->old_distance[1] ==
        old_distance[2]) {
        return true;
    }
    return false;
}
