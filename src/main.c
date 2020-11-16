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

#include <stdio.h>
#include <engine.h>

#include "example.h"

int main(int argc, char const *argv[])
{
    example_t *example = example_create();
    game_t game = {
        .update = ex_update,
        .draw = ex_draw,
        .handle_key = ex_handle_key,
        .content = example
    };
    engine_create("My Engine", 1920, 1080, false);
    engine_set_game(&game);
    engine_launch();
    engine_destroy();
    example_destroy(example);
    return EXIT_SUCCESS;
}
