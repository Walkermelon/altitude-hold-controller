#include <stdio.h>
#include <stdlib.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "physics-engine.h"
#include "ball.h"
#include "PID.h"

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 800
int main(int argc, char *argv[]) {
    PhysicsEngine *engine = calloc(1, sizeof(PhysicsEngine));
    if (engine == NULL) {
        fprintf(stderr, "Failed to allocate physics engine\n");
        return 1;
    }

    BallList *ball_list = ballListInit();

    start_physics_engine(engine, SCREEN_WIDTH, SCREEN_HEIGHT);
    while (update_physics_engine(engine, ball_list)) {
        SDL_SetRenderDrawColor(engine->renderer, 255, 255, 255, 255);
        SDL_RenderClear(engine->renderer);

        BallNode *current = ball_list->node;
        while (current != NULL) {
            printf("Ball position: (%d, %d)\n", current->ball->ax, current->ball->ax);
            PID(current->ball, 500, 400);
            update_ball_position(current->ball, SCREEN_WIDTH, SCREEN_HEIGHT);
            display_ball(engine->renderer, current->ball);
            current = current->next;
        }

        SDL_RenderPresent(engine->renderer);

        SDL_Delay(5); // Delay to cap frame rate at 100 FPS
    }
    SDL_Log("Calling Quit");
    stop_physics_engine(engine);

    SDL_Log("Freeing BallList");
    freeBallList(ball_list);
    SDL_Log("Freeing Engine");
    free(engine);
    SDL_Log("Done Freeing");
    
    return 0;
}