/**
 * @file settings.c
 * @author Gabriel Hamel (gabriel.hamel.pro@gmail.com)
 * @brief
 * @version 1.0
 * @date 2020-11-16
 *
 * @copyright Copyright (c) 2020
 *
 */


#include "engine.h"
#include "engine_private.h"

void engine_set_game(game_t *game)
{
    engine_t *engine = engine_get();

    engine->game = game;
}

void engine_set_refresh_rate(float milliseconds)
{
    engine_t *engine = engine_get();

    engine->refresh_rate = milliseconds;
}
