#include "PID.h"
#include "ball.h"
//This function should only controll the acceleration of the ball
void PID(Ball *ball, float setPointX, float setPointY){
    float errorX = setPointX - ball->x;
    float errorY = setPointY - ball->y;

    ball->ax = ball->kp * errorX + ball->ki * ball->sumErrorX + ball->kd * (ball->vx);
    ball->ay = ball->kp * errorY + ball->ki * ball->sumErrorY + ball->kd * (ball->vy);

    ball->sumErrorX += errorX * ball->ki;
    ball->sumErrorY += errorY * ball->ki;

}