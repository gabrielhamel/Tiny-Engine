/**
 * @file engine.h
 * @author Gabriel Hamel (gabriel.hamel.pro@gmail.com)
 * @brief
 * @version 1.0
 * @date 2020-11-15
 *
 * @copyright Copyright (c) 2020
 *
 */

#ifndef ENGINE_H
#define ENGINE_H

#include "window.h"

#define ENGINE() (engine_get())
#define GET_WINDOW(engine) (engine->window->window)
#define GET_CURRENT_KEY(engine) (engine->event.key.code)
#define KEY_VALUE(code) (sfKeyboard_isKeyPressed(code))

typedef struct {
    window_t *window;
    sfEvent event;
    float ellaspsedTime;
} engine_t;

engine_t *engine_get(void);
void engine_create( const char *title,
                    unsigned int width,
                    unsigned int height,
                    bool fullscreen);
void engine_destroy(void);
void engine_launch(void);
void engine_stop(void);
void engine_update(void);
void engine_draw(void);
void engine_handle_event(void);
void engine_handle_key(bool pressed);

#endif // ENGINE_H
