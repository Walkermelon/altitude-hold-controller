#include "ball.h"
#include <SDL3/SDL.h>
#include <stdlib.h>

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

BallList* ballListInitialize(Ball *ball) {
    BallList *list = malloc(sizeof(BallList));
    if (list == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to allocate ball list\n");
        return NULL;
    }
    list->ball = ball;
    list->next = NULL;
    return list;
}

Ball* ballInitialize(int x, int y, int vx, int vy, int radius) {
    Ball *ball = malloc(sizeof(Ball));
    RGBColor defaultColor = {0, 0, 255}; // Default color (blue)
    if (ball == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to allocate ball\n");
        return NULL;
    }
    ball->x = x;
    ball->y = y;
    ball->vx = vx;
    ball->vy = vy;
    ball->color = defaultColor;
    ball->radius = radius;
    return ball;
}

void freeBallList(BallList *list) {
    BallList *current = list;
    while (current != NULL) {
        BallList *next = current->next;
        free(current->ball);
        free(current);
        current = next;
    }
}

BallList* addBallToList(BallList *list, Ball *ball) {
    BallList *newNode = malloc(sizeof(BallList));
    if (newNode == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Failed to allocate new ball list node\n");
        return list; // Return the original list if allocation fails
    }
    newNode->ball = ball;
    newNode->next = list;
    return newNode; // New node becomes the new head of the list
}

