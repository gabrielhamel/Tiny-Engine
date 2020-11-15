/**
 * @file window.h
 * @author Gabriel Hamel (gabriel.hamel.pro@gmail.com)
 * @brief
 * @version 1.0
 * @date 2020-11-15
 *
 * @copyright Copyright (c) 2020
 *
 */

#ifndef WINDOW_H
#define WINDOW_H

#include <stdlib.h>
#include <stdbool.h>
#include <SFML/Graphics.h>

typedef struct {
    unsigned int width;
    unsigned int height;
    sfRenderWindow *window;
    sfClock *time;
} window_t;

window_t *window_create(const char *title,
                        unsigned int width,
                        unsigned int height,
                        bool fullscreen);
void window_destroy(window_t *window);

#endif // WINDOW_H
