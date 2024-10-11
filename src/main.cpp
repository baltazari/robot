#include <Arduino.h>
#include <Robot.h>
// #include <avr8-stub.h>
// #include <app_api.h>

Robot robot;

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  

  // Ultra_sensor_init();
  // servo_init();
  robot.servo_init();
}

void loop()
{
  robot.Servo_move();

  // servo_move();

  // Serial.println(actual_distance());
}

// int main()
// {
//   Robot robot;
//   while (true)
//   {
//     robot.forward();
//   }
// }