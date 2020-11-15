/**
 * @file keyboard.c
 * @author Gabriel Hamel (gabriel.hamel.pro@gmail.com)
 * @brief
 * @version 1.0
 * @date 2020-11-15
 *
 * @copyright Copyright (c) 2020
 *
 */

#include "engine.h"

void engine_handle_key(bool pressed)
{
    engine_t *engine = ENGINE();
    sfKeyCode code = GET_CURRENT_KEY(engine);

    if (pressed && code == sfKeyEscape) {
        engine_stop();
    }
}
