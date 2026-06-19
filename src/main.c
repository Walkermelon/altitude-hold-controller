#include <stdio.h>
#include <stdlib.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "physics-engine.h"
#include "ball.h"
int main(int argc, char *argv[]) {
    PhysicsEngine *engine = calloc(1, sizeof(PhysicsEngine));
    if (engine == NULL) {
        fprintf(stderr, "Failed to allocate physics engine\n");
        return 1;
    }

    BallList *ball_list = ballListInitialize(ballInitialize(400, 300, 1, 1));
    ball_list = addBallToList(ball_list, ballInitialize(400, 300, -1, -1));

    start_physics_engine(engine);
    while (update_physics_engine(engine)) {
        SDL_SetRenderDrawColor(engine->renderer, 255, 255, 255, 255);
        SDL_RenderClear(engine->renderer);

        BallList *current = ball_list;
        while (current != NULL) {
            printf("Ball position: (%d, %d)\n", current->ball->x, current->ball->y);
            update_ball_position(current->ball);

            display_ball(engine->renderer, current->ball);
            current = current->next;
        }

        SDL_Delay(100); // Delay to cap frame rate at 10 FPS
    }
    stop_physics_engine(engine);

    freeBallList(ball_list);
    free(engine);
    return 0;
}