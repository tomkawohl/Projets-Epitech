/*
** EPITECH PROJECT, 2022
** w_clock
** File description:
** w_clock_init
*/
#include "../../include/w_csfml.h"

w_clock_t *w_clock_init(void)
{
    w_clock_t *w_clock;
    w_clock = malloc(sizeof(w_clock_t));
    if (!w_clock)
        return (NULL);
    w_clock->hour = 0;
    w_clock->minute = 0;
    w_clock->second = 0;
    w_clock->microsecond = 0;
    w_clock->clock = sfClock_create();
    return (w_clock);
}
