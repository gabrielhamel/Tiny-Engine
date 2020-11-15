/**
 * @file pipeline.c
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

bool engine_clock(void)
{
    engine_t *engine = engine_get();
    float clock_time = sfTime_asSeconds(sfClock_getElapsedTime(engine->time));

    if (clock_time >= engine->refresh_rate) {
        engine->elaspsed_time = sfTime_asSeconds(
                                    sfClock_restart(engine->time));
        return true;
    }
    return false;
}

void engine_handle_event(void)
{
    engine_t *engine = engine_get();

    switch (engine->event.type) {
        case sfEvtClosed:
            engine_stop();
            break;
        case sfEvtKeyPressed:
            engine_handle_key(true);
            break;
        case sfEvtKeyReleased:
            engine_handle_key(false);
            break;
        default:
            break;
    }
}

void engine_update(void)
{
    engine_t *engine = engine_get();

    engine->game->update(engine->game->content, engine->elaspsed_time);
}

void engine_draw(void)
{
    engine_t *engine = engine_get();

    engine->game->draw(engine->game->content, engine->window);
}
