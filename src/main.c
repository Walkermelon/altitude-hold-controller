#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include "physics-engine.h"
#include "ball.h"
#include "PID.h"
#include "ui.h"

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
    UI *ui = ui_init(engine->window, engine->renderer);
    PIDGains gains = { .kp = 0.01f, .ki = 0.0001f, .kd = 0.1f };
    WindConfig wind = { .speed = 1.0f };

    while (update_physics_engine(engine, ball_list, ui)) {
        ui_build_panel(ui, &gains, &wind);

        const bool *keys = SDL_GetKeyboardState(NULL);
        float windDx = (keys[SDL_SCANCODE_RIGHT] ? 1.0f : 0.0f) - (keys[SDL_SCANCODE_LEFT] ? 1.0f : 0.0f);
        float windDy = (keys[SDL_SCANCODE_DOWN] ? 1.0f : 0.0f) - (keys[SDL_SCANCODE_UP] ? 1.0f : 0.0f);
        if (windDx != 0.0f && windDy != 0.0f) {
            windDx *= 0.70710678f; // normalize diagonal gust to the same magnitude as an axis-aligned gust
            windDy *= 0.70710678f;
        }
        float windAx = windDx * wind.speed;
        float windAy = windDy * wind.speed;

        SDL_SetRenderDrawColor(engine->renderer, 255, 255, 255, 255);
        SDL_RenderClear(engine->renderer);

        BallNode *current = ball_list->node;
        while (current != NULL) {
            //printf("Ball Acceleration: (%f, %f)\n", current->ball->ax, current->ball->ay);
            current->ball->kp = gains.kp;
            current->ball->ki = gains.ki;
            current->ball->kd = gains.kd;
            PID(current->ball, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
            current->ball->ax += windAx;
            current->ball->ay += windAy;
            update_ball_position(current->ball, SCREEN_WIDTH, SCREEN_HEIGHT);
            display_ball(engine->renderer, current->ball);
            current = current->next;
        }

        ui_render(ui);
        SDL_RenderPresent(engine->renderer);

        SDL_Delay(5); // Delay to cap frame rate at 100 FPS
    }


    SDL_Log("Calling Quit");
    ui_shutdown(ui);
    stop_physics_engine(engine);
    SDL_Log("Freeing BallList");
    freeBallList(ball_list);
    SDL_Log("Freeing Engine");
    free(engine);
    SDL_Log("Done Freeing");

    return 0;
}