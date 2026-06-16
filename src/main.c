#include <stdio.h>
#include <stdlib.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "physics-engine.h"
int main(int argc, char *argv[]) {
    PhysicsEngine *engine = calloc(1, sizeof(PhysicsEngine));
    if (engine == NULL) {
        fprintf(stderr, "Failed to allocate physics engine\n");
        return 1;
    }

    start_physics_engine(engine);
    while (update_physics_engine(engine)) {
        SDL_SetRenderDrawColor(engine->renderer, 150, 20, 100, 255);
        SDL_RenderClear(engine->renderer);
        SDL_RenderPresent(engine->renderer);
    }
    stop_physics_engine(engine);
    free(engine);
    return 0;
}