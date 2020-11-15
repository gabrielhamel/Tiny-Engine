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

#include "game.h"

void engine_create( const char *title,
                    unsigned int width,
                    unsigned int height,
                    bool fullscreen);
void engine_destroy(void);
void engine_launch(void);
void engine_stop(void);
void engine_set_game(game_t *game);
void engine_set_refresh_rate(float seconds);
window_t *engine_get_window(void);

#endif // ENGINE_H
