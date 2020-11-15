/**
 * @file main.c
 * @author Gabriel Hamel (gabriel.hamel.pro@gmail.com)
 * @brief
 * @version 1.0
 * @date 2020-11-15
 *
 * @copyright Copyright (c) 2020
 *
 */

#include "engine.h"

typedef struct {

} duckhunt_t;

void update(duckhunt_t *game, float elapsed_time)
{

}

void draw(duckhunt_t *game, window_t *window)
{

}

void handle_key(duckhunt_t *game, sfKeyCode code, bool pressed)
{
    if (pressed && code == sfKeyEscape) {
        engine_stop();
    }
}

int main(int argc, char const *argv[])
{
    duckhunt_t duckhunt = {0};
    game_t game = {
        .update = update,
        .draw = draw,
        .handle_key = handle_key,
        .content = &duckhunt
    };
    engine_create("My Engine", 1920, 1080, false);
    engine_set_game(&game);
    engine_launch();
    engine_destroy();
    return EXIT_SUCCESS;
}
