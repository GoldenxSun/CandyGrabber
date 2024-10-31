#ifndef CANDY_GRABBER_H
#define CANDY_GRABBER_H

#include <Arduino.h>

class CandyGrabber
{
public:
    CandyGrabber();
    void setup();
    void loop();

private:
    const int start_button = 4;

    const int grabber_1 = 6;
    const int grabber_2 = 5;
    const int EN_Grabber = 7;

    const int motor1_1 = 17;
    const int motor1_2  = 18;
    const int EN_1 = 9;

    const int motor2_1 = 16;
    const int motor2_2  = 15;
    const int EN_2 = 10;

    const int switch_1 = 8;
    const int switch_2 = 3;
    const int switch_3 = 11;
    const int switch_4 = 12;

    const int left = 40;
    const int right = 39;
    const int back = 38;
    const int forth = 37;
    const int up = 42;
    const int down = 41;


    // Game Variables
    int motor_speed;
    unsigned long startTime;
    const unsigned long gameDuration = 15000;
    bool gameActive = false;

    // Sensor States
    bool bswitchLeft, bswitchRight, bswitchBack, bswitchForth;
    bool bleft, bright, bback, bforth, bup, bdown;

    // Motor and grabber control functions
    void GrabberUp(int speed);
    void GrabberDown(int speed);
    void GrabberStop();
    void MoveLeft(int speed);
    void MoveRight(int speed);
    void StopMotor_1();
    void MoveBackward(int speed);
    void MoveForeward(int speed);
    void StopMotor_2();
    void handleXMovement();
    void handleYMovement();
    void handleZMovement();
};

#endif // CANDY_GRABBER_H