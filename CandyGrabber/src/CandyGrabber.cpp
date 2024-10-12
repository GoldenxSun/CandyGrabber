#include "CandyGrabber.h"

CandyGrabber::CandyGrabber() : motor_speed(100) {}

void CandyGrabber::setup()
{
    pinMode(start_button, INPUT);
    pinMode(motor1_1, OUTPUT);
    pinMode(motor1_2, OUTPUT);
    pinMode(EN_1, OUTPUT);
    pinMode(motor2_1, OUTPUT);
    pinMode(motor2_2, OUTPUT);
    pinMode(EN_2, OUTPUT);
    pinMode(grabber_1, OUTPUT);
    pinMode(grabber_2, OUTPUT);
    pinMode(EN_Grabber, OUTPUT);
    pinMode(switch_1, INPUT);
    pinMode(switch_2, INPUT);
    pinMode(switch_3, INPUT);
    pinMode(switch_4, INPUT);
    pinMode(left, INPUT);
    pinMode(right, INPUT);
    pinMode(back, INPUT);
    pinMode(forth, INPUT);
    pinMode(up, INPUT);
    pinMode(down, INPUT);
}

void CandyGrabber::loop()
{
    if (!gameActive && digitalRead(start_button) == HIGH)
    {
        gameActive = true;
        startTime = millis();
    }

    if (gameActive)
    {
        bleft = digitalRead(left);
        bright = digitalRead(right);
        bback = digitalRead(back);
        bforth = digitalRead(forth);
        bup = digitalRead(up);
        bdown = digitalRead(down);

        bswitchLeft = digitalRead(switch_4);
        bswitchRight = digitalRead(switch_1);
        bswitchBack = digitalRead(switch_2);
        bswitchForth = digitalRead(switch_3);

        handleXMovement();
        handleYMovement();
        handleZMovement();

        if (millis() - startTime >= gameDuration)
        {
            gameActive = false;

            GrabberUp(motor_speed);
            delay(5000);
            GrabberStop();

            MoveLeft(motor_speed);
            while (bleft)
            {
            }
            StopMotor_1();

            MoveBackward(motor_speed);
            while (bback)
            {
            }
            StopMotor_2();

            GrabberDown(motor_speed);
            delay(2000);
            GrabberStop();
        }
    }
}

void CandyGrabber::GrabberUp(int speed)
{
    digitalWrite(grabber_1, LOW);
    digitalWrite(grabber_2, HIGH);
    analogWrite(EN_Grabber, speed);
}

void CandyGrabber::GrabberDown(int speed)
{
    digitalWrite(grabber_2, LOW);
    digitalWrite(grabber_1, HIGH);
    analogWrite(EN_Grabber, speed);
}

void CandyGrabber::GrabberStop()
{
    digitalWrite(grabber_1, LOW);
    digitalWrite(grabber_2, LOW);
}

void CandyGrabber::MoveLeft(int speed)
{
    digitalWrite(motor1_1, LOW);
    digitalWrite(motor1_2, HIGH);
    analogWrite(EN_1, speed);
}

void CandyGrabber::MoveRight(int speed)
{
    digitalWrite(motor1_2, LOW);
    digitalWrite(motor1_1, HIGH);
    analogWrite(EN_1, speed);
}

void CandyGrabber::StopMotor_1()
{
    digitalWrite(motor1_1, LOW);
    digitalWrite(motor1_2, LOW);
}

void CandyGrabber::MoveBackward(int speed)
{
    digitalWrite(motor2_1, LOW);
    digitalWrite(motor2_2, HIGH);
    analogWrite(EN_2, speed);
}

void CandyGrabber::MoveForeward(int speed)
{
    digitalWrite(motor2_2, LOW);
    digitalWrite(motor2_1, HIGH);
    analogWrite(EN_2, speed);
}

void CandyGrabber::StopMotor_2()
{
    digitalWrite(motor2_1, LOW);
    digitalWrite(motor2_2, LOW);
}

void CandyGrabber::handleXMovement()
{
    if (bswitchLeft && bleft)
    {
        MoveLeft(motor_speed);
    }
    else if (bswitchRight && bright)
    {
        MoveRight(motor_speed);
    }
    else
    {
        StopMotor_1();
    }
}

void CandyGrabber::handleYMovement()
{
    if (bswitchForth && bforth)
    {
        MoveForeward(motor_speed);
    }
    else if (bswitchBack && bback)
    {
        MoveBackward(motor_speed);
    }
    else
    {
        StopMotor_2();
    }
}

void CandyGrabber::handleZMovement()
{
    if (bup)
    {
        GrabberUp(motor_speed);
    }
    else if (bdown)
    {
        GrabberDown(motor_speed);
    }
    else
    {
        GrabberStop();
    }
}
