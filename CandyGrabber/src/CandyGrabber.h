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
    const int start_button = 0;

    const int grabber_1 = 2;
    const int grabber_2 = 1;
    const int EN_Grabber = 3;

    const int motor1_1 = 6;
    const int motor1_2  = 7;
    const int EN_1 = 10;

    const int motor2_1 = 5;
    const int motor2_2  = 4;
    const int EN_2 = 11;

    const int switch_1 = 8;
    const int switch_2 = 9;
    const int switch_3 = 12;
    const int switch_4 = 13;

    const int left = A3;
    const int right = A2;
    const int back = A1;
    const int forth = A0;
    const int up = A5;
    const int down = A4;


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
