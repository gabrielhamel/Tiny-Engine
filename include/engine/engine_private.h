/**
 * @file engine_private.h
 * @author Gabriel Hamel (gabriel.hamel.pro@gmail.com)
 * @brief
 * @version 1.0
 * @date 2020-11-16
 *
 * @copyright Copyright (c) 2020
 *
 */

#ifndef ENGINE_PRIVATE_H
#define ENGINE_PRIVATE_H

#include "window.h"
#include "game.h"

#define GET_WINDOW(engine) (engine->window->window)
#define GET_CURRENT_KEY(engine) (engine->event.key.code)
#define KEY_VALUE(code) (sfKeyboard_isKeyPressed(code))

void engine_update(void);
void engine_draw(void);
void engine_handle_event(void);
void engine_handle_key(bool pressed);

#endif // ENGINE_PRIVATE_H
