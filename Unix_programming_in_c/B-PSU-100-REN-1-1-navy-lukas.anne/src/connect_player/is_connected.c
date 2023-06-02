/*
** EPITECH PROJECT, 2022
** connect_player
** File description:
** is_connected
*/
#include "src.h"

int is_connected(int flag)
{
    static int is_connected = FALSE;
    if (flag == TRUE)
        is_connected = TRUE;
    return (is_connected);
}
