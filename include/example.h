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

typedef struct {

} example_t;

void ex_update(void *game, float elapsed_time);
void ex_draw(void *game, window_t *window);
void ex_handle_key(void *game, sfKeyCode code, bool pressed);

#endif // EXAMPLE_H
