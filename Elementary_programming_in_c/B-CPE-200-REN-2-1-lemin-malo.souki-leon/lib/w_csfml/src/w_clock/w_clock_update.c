/*
** EPITECH PROJECT, 2022
** w_clock
** File description:
** w_clock_update
*/
#include "../../include/w_csfml.h"

void w_clock_update(w_clock_t *w_clock)
{
    sfTime time = sfClock_getElapsedTime(w_clock->clock);
    w_clock->microsecond = sfTime_asMicroseconds(time);
    if (w_clock->microsecond > 1000000) {
        w_clock->second++;
        sfClock_restart(w_clock->clock);
        if (w_clock->second == 60) {
        w_clock->second = 0;
        w_clock->minute++;
    }
        if (w_clock->minute == 60) {
            w_clock->minute = 0;
            w_clock->hour++;
        }
    }
}
