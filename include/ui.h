#ifndef UI_H_
#define UI_H_

#include <SDL3/SDL.h>
#include <stdbool.h>

typedef struct PIDGains {
    float kp;
    float ki;
    float kd;
} PIDGains;

typedef struct WindConfig {
    float speed;
} WindConfig;

typedef struct UI UI;

UI* ui_init(SDL_Window *window, SDL_Renderer *renderer);
void ui_process_event(UI *ui, SDL_Event *event);
void ui_begin_input(UI *ui);
void ui_end_input(UI *ui);
bool ui_is_hovered(UI *ui);
void ui_build_panel(UI *ui, PIDGains *gains, WindConfig *wind);
void ui_render(UI *ui);
void ui_shutdown(UI *ui);

#endif // UI_H_
