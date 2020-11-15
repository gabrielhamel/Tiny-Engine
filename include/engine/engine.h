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

typedef struct {
    window_t *window;
    sfEvent event;
    float elaspsed_time;
    game_t *game;
} engine_t;

engine_t *engine_get(void);
void engine_create( const char *title,
                    unsigned int width,
                    unsigned int height,
                    bool fullscreen);
void engine_destroy(void);
void engine_launch(void);
void engine_stop(void);
void engine_set_game(game_t *game);

#endif // ENGINE_H
