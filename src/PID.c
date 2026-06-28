#include "PID.h"
#include "ball.h"
//This function should only controll the acceleration of the ball
void PID(Ball *ball, float setPointX, float setPointY){
    float kp = 0.001f;  // Proportional gain (for testing purposes)
    float ki = 0.001f;  // Integral gain (for testing purposes)
    float kd = 0.001f; // Differential gain (for testing purposes)

    float errorX = setPointX - ball->x;
    float errorY = setPointY - ball->y;

    ball->ax = kp * errorX + ki * ball->sumErrorX + kd * (ball->vx);
    ball->ay = kp * errorY + ki * ball->sumErrorY + kd * (ball->vy);

    ball->sumErrorX += errorX * ki;
    ball->sumErrorY += errorY * ki;

}