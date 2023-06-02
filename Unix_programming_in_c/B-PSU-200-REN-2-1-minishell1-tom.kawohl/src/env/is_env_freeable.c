/*
** EPITECH PROJECT, 2022
** env
** File description:
** is_env_freeable
*/
#include "src.h"

int is_env_freeable(int set)
{
    static int is_freeable = FALSE;
    if (set == TRUE) {
        is_freeable = TRUE;
    }
    return (is_freeable);
}
