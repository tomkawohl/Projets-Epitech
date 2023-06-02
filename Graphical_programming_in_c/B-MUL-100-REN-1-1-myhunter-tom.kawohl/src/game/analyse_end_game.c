/*
** EPITECH PROJECT, 2022
** analyse_end_game
** File description:
** analyse_end_game
*/
#include "my_all.h"
#include "my_printf.h"
#include "src.h"
#include <time.h>

void analyse_end_game(sfRenderWindow *window, sfEvent event)
{
    if (event.type == sfEvtClosed)
        close_window(window);
}
