/**
 * @file window.c
 * @author Gabriel Hamel (gabriel.hamel.pro@gmail.com)
 * @brief
 * @version 1.0
 * @date 2020-11-15
 *
 * @copyright Copyright (c) 2020
 *
 */

#include "engine.h"
#include "engine_private.h"

window_t *window_create(const char *title,
                        unsigned int width,
                        unsigned int height,
                        bool fullscreen)
{
    window_t *res = malloc(sizeof(window_t));

    res->width = width;
    res->height = height;
    res->window = sfRenderWindow_create((sfVideoMode){width, height, 32},
                                        title,
                                        fullscreen ? sfFullscreen : sfClose,
                                        NULL);
    sfRenderWindow_setKeyRepeatEnabled(res->window, sfFalse);
    sfRenderWindow_setVerticalSyncEnabled(res->window, sfTrue);
    res->time = sfClock_create();
    return res;
}

void window_destroy(window_t *window)
{
    sfRenderWindow_destroy(window->window);
    sfClock_destroy(window->time);
    free(window);
}
