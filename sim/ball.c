#include "ball.h"

void update_ball_position(Ball *ball){
    ball->x += ball->vx;
    ball->y += ball->vy;
}

