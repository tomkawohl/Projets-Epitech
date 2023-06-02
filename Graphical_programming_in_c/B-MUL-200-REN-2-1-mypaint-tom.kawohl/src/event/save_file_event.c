/*
** EPITECH PROJECT, 2023
** src/event/save_file_event.c
** File description:
** file saving event
*/

#include "my_paint.h"

void save_file_event(sfEvent event, paint_t *info)
{
    static int can_save = true;
    if (sfKeyboard_isKeyPressed(sfKeyS)
        && sfKeyboard_isKeyPressed(sfKeyLControl)
        && can_save == true) {
        save_file(info);
        can_save = false;
    }
    if (event.type == sfEvtKeyReleased)
        can_save = true;
}
