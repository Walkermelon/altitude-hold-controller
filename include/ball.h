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
    float vx;
    float vy;
    float ax;
    float ay;
    float sumErrorX;
    float sumErrorY;
    float kp;
    float ki;
    float kd;
    RGBColor color;
    int radius;

} Ball;

typedef struct BallNode {
    struct BallNode *next;
    Ball *ball;
} BallNode;

typedef struct BallList {
    BallNode* node;
    int size;
} BallList;

void update_ball_position(Ball *ball, int SCREEN_WIDTH, int SCREEN_HEIGHT);
void display_ball(SDL_Renderer *renderer, Ball *ball);
BallList* ballListInit();
Ball* ballInit(int x, int y, float vx, float vy, int radius, float kp, float ki, float kd);
void freeBallList(BallList *list);
void addBallToList(BallList *list, Ball *ball);
void printBalls(BallList *list);


#endif // BALL_H_