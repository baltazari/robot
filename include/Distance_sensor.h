#include <pins_arduino.h>
// int actual_distance();
// void Ultra_sensor_init();
// const int trigPin = A0;
// const int echoPin = A1;
// const int min_distance = 15;
class Distance_sensor
{
private:
    int trigPin;
    int echoPin;
    int min_distance;
    long duration;
    int distance;

public:
    Distance_sensor();
    int Actual_distance();
    int Get_min_distance();
};