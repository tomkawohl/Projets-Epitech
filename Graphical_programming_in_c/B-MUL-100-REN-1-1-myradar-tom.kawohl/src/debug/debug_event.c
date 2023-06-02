/*
** EPITECH PROJECT, 2022
** src
** File description:
** debug_init_element
*/
#include "src.h"

void debug_event(sfRenderWindow *win, sfEvent *event,object_t **planes)
{
    while (sfRenderWindow_pollEvent(win, event)) {
        if (event->type == sfEvtClosed)
        sfRenderWindow_close(win);
        if (sfKeyboard_isKeyPressed(sfKeyRight))
            obj_move(planes[0], (sfVector2f){5.0, 0.0});
        if (sfKeyboard_isKeyPressed(sfKeyLeft))
            obj_move(planes[0], (sfVector2f){-5.0, 0.0});
        if (sfKeyboard_isKeyPressed(sfKeyUp))
            obj_move(planes[0], (sfVector2f){0.0, -5.0});
        if (sfKeyboard_isKeyPressed(sfKeyDown))
            obj_move(planes[0], (sfVector2f){0.0, 5.0});
        if (sfKeyboard_isKeyPressed(sfKeyR))
            debug_obj_rotate(planes[0]);
    }
}
