/*
** EPITECH PROJECT, 2022
** src
** File description:
** planes_move
*/
#include "src.h"

void check_delay(object_t **planes, int i, w_clock_t *w_clock)
{
    if (planes[i]->has_took_off == TRUE)
        return;
    if (w_clock->second + (w_clock->minute * 60) >= planes[i]->delay)
        planes[i]->has_took_off = TRUE;
}

void planes_move(object_t **planes, w_clock_t *w_clock)
{
    int i = 0;
    int can_move = FALSE;
    char *str = int_to_string(w_clock->microsecond);
    if (!str) return;
    static char time1 = 'a';
    static char time2 = 'a';
    time1 = str[0];
    if (time1 != time2 && time2 != 'a' && w_clock->microsecond > 100000)
        can_move = TRUE;
    while (planes[i] != NULL) {
        check_delay(planes, i, w_clock);
        if (planes[i]->is_crashed == FALSE &&
        planes[i]->has_landed == FALSE && can_move == TRUE) {
            obj_move_to(planes[i], w_clock, planes[i]->dep, planes[i]->arr);
        }
        i++;
    }
    time2 = time1;
    free(str);
}
