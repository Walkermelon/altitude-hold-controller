#ifndef physics_engine_H_
#define physics_engine_H_
#include <stdbool.h>
#include <SDL3/SDL.h>
#include "ball.h"
typedef struct PhysicsEngine {
    bool running;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Event event;
} PhysicsEngine;
void start_physics_engine(PhysicsEngine *engine, int SCREEN_WIDTH, int SCREEN_HEIGHT);
bool update_physics_engine(PhysicsEngine *engine, BallList* list);
void stop_physics_engine(PhysicsEngine *engine);
#endif // physics_engine_H_
