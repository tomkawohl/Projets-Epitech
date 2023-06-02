/*
** EPITECH PROJECT, 2022
** src
** File description:
** state_touhed
*/
#include "src.h"

int state_early(int state, int reset)
{
    static int is_early_state = FALSE;
    if (reset == TRUE) {
        is_early_state = FALSE;
    }
    if (state == TRUE) {
        is_early_state = TRUE;
    }
    return (is_early_state);
}

int state_touched(int state, int reset)
{
    static int is_touched_state = -1;
    if (reset == TRUE) {
        is_touched_state = -1;
    }
    if (state == TRUE)
        is_touched_state = TRUE;
    if (state == FALSE)
        is_touched_state = FALSE;
    return (is_touched_state);
}
