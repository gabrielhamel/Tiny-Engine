/**
 * @file engine.c
 * @author Gabriel Hamel (gabriel.hamel.pro@gmail.com)
 * @brief
 * @version 1.0
 * @date 2020-11-15
 *
 * @copyright Copyright (c) 2020
 *
 */

#include "engine.h"

engine_t *engine_get(void)
{
    static engine_t *engine = NULL;

    if (!engine) {
        engine = malloc(sizeof(engine_t));
    }
    return engine;
}

void engine_create(const char *title,
                        unsigned int width,
                        unsigned int height,
                        bool fullscreen)
{
    engine_t *engine = ENGINE();

    engine->window = window_create(title, width, height, fullscreen);
    engine->ellaspsedTime = 0;
    engine->event = (sfEvent){0};
}

void engine_destroy(void)
{
    engine_t *engine = ENGINE();

    window_destroy(engine->window);
    free(engine);
}

void engine_launch(void)
{
    engine_t *engine = ENGINE();

    while (sfRenderWindow_isOpen(GET_WINDOW(engine))) {
        while (sfRenderWindow_pollEvent(GET_WINDOW(engine),
                                        &engine->event)) {
            engine_handle_event();
        }
        engine->ellaspsedTime =
            sfTime_asSeconds(sfClock_restart(engine->window->time));
        engine_update();
        sfRenderWindow_clear(GET_WINDOW(engine), sfBlack);
        engine_draw();
        sfRenderWindow_display(GET_WINDOW(engine));
    }
}

void engine_stop()
{
    engine_t *engine = ENGINE();

    sfRenderWindow_close(GET_WINDOW(engine));
}
