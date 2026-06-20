#include "ball.h"
#include <SDL3/SDL.h>
#include <stdlib.h>
#include <stdio.h>

void update_ball_position(Ball *ball, int SCREEN_WIDTH, int SCREEN_HEIGHT){
    if(ball->x + ball->radius >= SCREEN_WIDTH || ball->x <= 0){
        ball->vx *= -1;
    }
    if(ball->y + ball->radius >= SCREEN_HEIGHT || ball->y <= 0){
        ball->vy *= -1;
    }
    ball->x += ball->vx;
    ball->y += ball->vy;
}

void display_ball(SDL_Renderer *renderer, Ball *ball) {
    SDL_SetRenderDrawColor(renderer, ball->color.r, ball->color.g, ball->color.b, 255);
    SDL_FRect rect = { ball->x, ball->y, ball->radius, ball->radius};
    SDL_RenderFillRect(renderer, &rect);
}

BallList* ballListInit() {
    BallList* ballList = malloc(sizeof(BallList));
    if(ballList == NULL){
        SDL_Log("Couldn't Malloc BallList");
        return NULL;
    }
    ballList->node = NULL;
    ballList->size = 0;
    return ballList;
}

Ball* ballInit(int x, int y, int vx, int vy, int radius) {
    Ball* ball = malloc(sizeof(Ball));
    if(ball == NULL){
        SDL_Log("Couldn't Malloc Ball");
        return NULL;
    }
    ball->color.r = 0;
    ball->color.g = 255;
    ball->color.b = 0;
    ball->radius = radius;
    ball->x = x;
    ball->y = y;
    ball->vx = vx;
    ball->vy = vy;
    return ball;
}

void freeBallList(BallList *list) {
    BallNode* curr = list->node;
    BallNode* next = list->node;
    while(curr != NULL){
        next = curr->next;
        free(curr->ball);
        free(curr);
        curr = next;
    }
    free(list);

}

void addBallToList(BallList *list, Ball *ball) {
    BallNode* node = malloc(sizeof(BallNode));
    node->ball = ball;
    node->next = list->node;
    list->node = node;
    list->size++;
}

