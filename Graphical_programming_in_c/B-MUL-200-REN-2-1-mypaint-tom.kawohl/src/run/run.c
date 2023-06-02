/*
** EPITECH PROJECT, 2023
** src/run/run.c
** File description:
** main run function
*/

#include "my_paint.h"

void run(paint_t *info)
{
    sfClock *refresh_clock = sfClock_create();

    while (sfRenderWindow_isOpen(info->window)) {
        handle_event(info);
        if (sfClock_getElapsedTime(refresh_clock).microseconds / 1000 > 1 /
                FPS) {
            sfRenderWindow_clear(info->window, TOP_HVR);
            sfClock_restart(refresh_clock);
            run_window_draw(info);
            sfRenderWindow_display(info->window);
        }
    }
}
