/*
** EPITECH PROJECT, 2022
** manage_events
** File description:
** manage_events
*/

#include "my_all.h"
#include "my_printf.h"
#include "src.h"

void analyse_events(sfRenderWindow *window, sfEvent event, object_t *tab)
{
    click_start(window,event, tab);
    if (event.type == sfEvtClosed)
        close_window(window);
}
