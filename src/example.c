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

#include <engine.h>

#include "example.h"

void ex_update(void *game, float elapsed_time)
{
    example_t *example = game;
    moving_rect_t *elem;

    if (example->click_cooldown > 0) {
        example->click_cooldown -= elapsed_time;
    }

    if (example->click_cooldown <= 0.f &&
    sfMouse_isButtonPressed(sfMouseLeft)) {
        example->click_cooldown = 0.5f;
        ex_add_entity(example);
    }
    LIST_FOREACH(elem, &example->moving_rects, entry) {
        moving_rect_update(elem, elapsed_time);
    }
}

void ex_draw(void *game, sfRenderWindow *window)
{
    example_t *example = game;
    moving_rect_t *elem;

    LIST_FOREACH(elem, &example->moving_rects, entry) {
        moving_rect_draw(elem, window);
    }
}

void ex_handle_key(void *game, sfKeyCode code, bool pressed)
{
    example_t *example = game;

    if (pressed && code == sfKeyEscape) {
        engine_stop();
    }
}

example_t *example_create(void)
{
    example_t *res = malloc(sizeof(example_t));

    LIST_INIT(&res->moving_rects);
    res->click_cooldown = 0.f;
    return res;
}

void example_destroy(example_t *example)
{
    // moving_rect_destroy(example->entity);
    free(example);
}
