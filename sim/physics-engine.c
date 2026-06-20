#include "physics-engine.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

#include <SDL3/SDL.h>

#define SDL_FLAGS SDL_INIT_VIDEO | SDL_INIT_EVENTS

//Assumes engine is already allocated and initialized to zero
void start_physics_engine(PhysicsEngine *engine, int SCREEN_WIDTH, int SCREEN_HEIGHT) {
    bool start = SDL_Init(SDL_FLAGS);
    if (start == 0) {
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
        return;
    }
    engine->running = true;
    engine->window = SDL_CreateWindow("Hello World", SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (engine->window == NULL) {
        SDL_Log("Could not create window: %s", SDL_GetError());
        SDL_Quit();
        return;
    }
    engine->renderer = SDL_CreateRenderer(engine->window, NULL);
    if (engine->renderer == NULL) {
        SDL_Log("Could not create renderer: %s", SDL_GetError());
        SDL_DestroyWindow(engine->window);
        SDL_Quit();
        return;
    }
    SDL_Log("Physics engine started successfully.");
}

bool update_physics_engine(PhysicsEngine *engine) {
    if (!engine->running) {
        return false;
    }
    while (SDL_PollEvent(&engine->event)) {
        if (engine->event.type == SDL_EVENT_QUIT) {
            SDL_Log("Quit event received. Stopping main loop.");
            return false;
        }
    }
    return true;
}

void stop_physics_engine(PhysicsEngine *engine) {
    if (!engine->running) {
        SDL_Log("Physics engine is not running.");
        return;
    }
    SDL_DestroyRenderer(engine->renderer);
    SDL_DestroyWindow(engine->window);
    SDL_Quit();
    engine->running = false;
    SDL_Log("Physics engine stopped.");
}