/**
 * @file main.c
 * @author Gabriel Hamel (gabriel.hamel.pro@gmail.com)
 * @brief
 * @version 1.0
 * @date 2020-11-15
 *
 * @copyright Copyright (c) 2020
 *
 */

#include "engine.h"

int main(int argc, char const *argv[])
{
    engine_create("My Engine", 1920, 1080, false);
    engine_launch();
    engine_destroy();
    return EXIT_SUCCESS;
}
