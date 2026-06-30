#include "PID.h"
#include "ball.h"
//This function should only controll the acceleration of the ball
#define CLAMP 20
void PID(Ball *ball, float setPointX, float setPointY){
    float errorX = setPointX - ball->x;
    float errorY = setPointY - ball->y;

    ball->ax = ball->kp * errorX + ball->ki * ball->sumErrorX - ball->kd * (ball->vx);
    ball->ay = ball->kp * errorY + ball->ki * ball->sumErrorY - ball->kd * (ball->vy);

    if(ball->ax >= CLAMP || ball->ax <= -CLAMP){
        ball->ax = (ball->ax > 0) ? CLAMP : -CLAMP;
    }
    else{
        ball->sumErrorX += errorX;
    }
    if(ball->ay >= CLAMP || ball->ay <= -CLAMP){
        ball->ay = (ball->ay > 0) ? CLAMP : -CLAMP;
    }
    else{
        ball->sumErrorY += errorY;
    }

}