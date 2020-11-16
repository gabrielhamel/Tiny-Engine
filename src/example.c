/**
 * @file example.c
 * @author Gabriel Hamel (gabriel.hamel.pro@gmail.com)
 * @brief
 * @version 1.0
 * @date 2020-11-16
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <stdio.h>
#include <engine.h>

#include "example.h"

void ex_update(void *game, float elapsed_time)
{
    (void)game;

    printf("update(%f)\n", elapsed_time);
}

void ex_draw(void *game, window_t *window)
{
    (void)game;
    (void)window;
}

void ex_handle_key(void *game, sfKeyCode code, bool pressed)
{
    (void)game;

    if (pressed && code == sfKeyEscape) {
        engine_stop();
    }
}
