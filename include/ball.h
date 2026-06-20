#ifndef BALL_H_  
#define BALL_H_

#include <SDL3/SDL_render.h>


typedef struct RGBColor {
    Uint8 r;
    Uint8 g;
    Uint8 b;
} RGBColor;
typedef struct Ball {
    int x;
    int y;
    int vx;
    int vy;
    RGBColor color;
    int radius;
} Ball;

typedef struct BallList {
    struct BallList *next;
    Ball *ball;
} BallList;

void update_ball_position(Ball *ball, int SCREEN_WIDTH, int SCREEN_HEIGHT);
void display_ball(SDL_Renderer *renderer, Ball *ball);
BallList* ballListInitialize(Ball *ball);
Ball* ballInitialize(int x, int y, int vx, int vy, int radius);
void freeBallList(BallList *list);
BallList* addBallToList(BallList *list, Ball *ball);


#endif // BALL_H_