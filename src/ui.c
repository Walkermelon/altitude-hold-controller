#include <SDL3/SDL.h>

#define NK_INCLUDE_FIXED_TYPES
#define NK_INCLUDE_STANDARD_IO
#define NK_INCLUDE_STANDARD_VARARGS
#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT
#define NK_INCLUDE_COMMAND_USERDATA
#define NK_IMPLEMENTATION
#include "nuklear/nuklear.h"

#define NK_SDL3_RENDERER_IMPLEMENTATION
#include "nuklear/nuklear_sdl3_renderer.h"

#include "ui.h"

struct UI {
    struct nk_context *ctx;
};

UI* ui_init(SDL_Window *window, SDL_Renderer *renderer) {
    UI *ui = SDL_malloc(sizeof(UI));
    if (ui == NULL) {
        SDL_Log("Couldn't allocate UI");
        return NULL;
    }

    ui->ctx = nk_sdl_init(window, renderer, nk_sdl_allocator());

    struct nk_font_atlas *atlas;
    struct nk_font_config config = nk_font_config(0);
    struct nk_font *font;
    atlas = nk_sdl_font_stash_begin(ui->ctx);
    font = nk_font_atlas_add_default(atlas, 15, &config);
    nk_sdl_font_stash_end(ui->ctx);
    nk_style_set_font(ui->ctx, &font->handle);

    return ui;
}

void ui_process_event(UI *ui, SDL_Event *event) {
    nk_sdl_handle_event(ui->ctx, event);
}

void ui_begin_input(UI *ui) {
    nk_input_begin(ui->ctx);
}

void ui_end_input(UI *ui) {
    nk_input_end(ui->ctx);
}

bool ui_is_hovered(UI *ui) {
    return nk_window_is_any_hovered(ui->ctx) || nk_item_is_any_active(ui->ctx);
}

void ui_build_panel(UI *ui, PIDGains *gains, WindConfig *wind) {
    struct nk_context *ctx = ui->ctx;
    if (nk_begin(ctx, "PID Tuning", nk_rect(20, 20, 260, 240),
            NK_WINDOW_BORDER | NK_WINDOW_MOVABLE | NK_WINDOW_TITLE)) {
        nk_layout_row_dynamic(ctx, 20, 1);
        nk_labelf(ctx, NK_TEXT_LEFT, "kp: %.5f", (double)gains->kp);
        nk_slider_float(ctx, 0.0f, &gains->kp, 0.2f, 0.0005f);

        nk_labelf(ctx, NK_TEXT_LEFT, "ki: %.5f", (double)gains->ki);
        nk_slider_float(ctx, 0.0f, &gains->ki, 0.01f, 0.00005f);

        nk_labelf(ctx, NK_TEXT_LEFT, "kd: %.5f", (double)gains->kd);
        nk_slider_float(ctx, 0.0f, &gains->kd, 1.0f, 0.001f);

        nk_labelf(ctx, NK_TEXT_LEFT, "gust speed: %.2f", (double)wind->speed);
        nk_slider_float(ctx, 0.0f, &wind->speed, 5.0f, 0.05f);
    }
    nk_end(ctx);
}

void ui_render(UI *ui) {
    nk_sdl_render(ui->ctx, NK_ANTI_ALIASING_ON);
}

void ui_shutdown(UI *ui) {
    nk_sdl_shutdown(ui->ctx);
    SDL_free(ui);
}
