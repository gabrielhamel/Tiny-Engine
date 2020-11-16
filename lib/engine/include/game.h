/**
 * @file game.h
 * @author Gabriel Hamel (gabriel.hamel.pro@gmail.com)
 * @brief
 * @version 1.0
 * @date 2020-11-15
 *
 * @copyright Copyright (c) 2020
 *
 */

#ifndef GAME_H
#define GAME_H

#include "window.h"

#include <SFML/Graphics.h>

typedef struct {
    void *content;
    void (*update)(void *content, float elapsed_time);
    void (*draw)(void *content, sfRenderWindow *window);
    void (*handle_key)(void *content, sfKeyCode code, bool pressed);
} game_t;

#endif // GAME_H
