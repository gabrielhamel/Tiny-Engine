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
    example_t *example = game;
    sfVector2f speed = {0, 0};

    speed.x += sfKeyboard_isKeyPressed(sfKeyD);
    speed.x -= sfKeyboard_isKeyPressed(sfKeyQ);
    speed.y -= sfKeyboard_isKeyPressed(sfKeyZ);
    speed.y += sfKeyboard_isKeyPressed(sfKeyS);

    speed.x *= 400.f * elapsed_time;
    speed.y *= 400.f * elapsed_time;

    sfRectangleShape_rotate(example->rect, 100.f * elapsed_time);
    sfRectangleShape_move(example->rect, speed);
}

void ex_draw(void *game, sfRenderWindow *window)
{
    example_t *example = game;

    sfRenderWindow_drawRectangleShape(window, example->rect, NULL);
}

void ex_handle_key(void *game, sfKeyCode code, bool pressed)
{
    if (pressed && code == sfKeyEscape) {
        engine_stop();
    }
}

example_t *example_create(void)
{
    example_t *res = malloc(sizeof(example_t));

    res->rect = sfRectangleShape_create();
    sfRectangleShape_setFillColor(res->rect, sfRed);
    sfRectangleShape_setPosition(res->rect, (sfVector2f){500, 300});
    sfRectangleShape_setSize(res->rect, (sfVector2f){50, 50});
    return res;
}

void example_destroy(example_t *example)
{
    sfRectangleShape_destroy(example->rect);
    free(example);
}
