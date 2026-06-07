#include "physics-engine.h"

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#define SDL_FLAGS SDL_INIT_VIDEO

typedef struct PhysicsEngine {
    bool running;
} PhysicsEngine;

//Assumes engine is already allocated and initialized to zero
void start_physics_engine(PhysicsEngine *engine) {
    bool start = SDL_Init(SDL_FLAGS);
    if (start != 0) {
       engine->running = true;
    }
    else{
        engine->running = false;
    }
    
}

void stop_physics_engine(PhysicsEngine *engine) {
    if (engine->running) {
        SDL_Quit();
        engine->running = false;
    }
}