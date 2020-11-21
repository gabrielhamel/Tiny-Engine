/**
 * @file example.h
 * @author Gabriel Hamel (gabriel.hamel.pro@gmail.com)
 * @brief
 * @version 1.0
 * @date 2020-11-16
 *
 * @copyright Copyright (c) 2020
 *
 */

#ifndef EXAMPLE_H
#define EXAMPLE_H

#include "game.h"
#include <sys/queue.h>

typedef struct moving_rect_s {
    LIST_ENTRY(moving_rect_s) entry;
    sfRectangleShape *rect;
} moving_rect_t;

typedef struct {
    float click_cooldown;
    LIST_HEAD(, moving_rect_s) moving_rects;
} example_t;

example_t *example_create(void);
void example_destroy(example_t *example);

void ex_update(void *game, float elapsed_time);
void ex_draw(void *game, sfRenderWindow *window);
void ex_handle_key(void *game, sfKeyCode code, bool pressed);

moving_rect_t *moving_rect_create(void);
void moving_rect_destroy(moving_rect_t *moving_rect);
void moving_rect_update(moving_rect_t *moving_rect, float elapsed_time);
void moving_rect_draw(moving_rect_t *moving_rect, sfRenderWindow *window);

void ex_add_entity(example_t *example);

#endif // EXAMPLE_H
