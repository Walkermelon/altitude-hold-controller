#ifndef BALL_H_  
#define BALL_H_


typedef struct Ball {
    float x;
    float y;
    float vx;
    float vy;
} Ball;

void update_ball_position(Ball *ball);

#endif // BALL_H_