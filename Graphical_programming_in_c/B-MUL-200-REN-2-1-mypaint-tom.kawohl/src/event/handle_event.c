/*
** EPITECH PROJECT, 2023
** src/event/handle_event
** File description:
** main event handler
*/

#include "my_paint.h"

void update_window(sfEvent event, paint_t *info)
{
    if (event.type == sfEvtResized) {
        info->window_size = sfRenderWindow_getSize(info->window);
    }
}

void set_move(sfEvent event, paint_t *info)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyM &&
        info->move == false) {
        info->move = true;
        info->moved.y = sfMouse_getPositionRenderWindow(info->window).y;
        info->moved.x = sfMouse_getPositionRenderWindow(info->window).x;
    }
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeyM) {
        info->move = false;
        info->moved.x = (float)sfMouse_getPositionRenderWindow(info->window).x -
            info->moved.x;
        info->moved.y = (float)sfMouse_getPositionRenderWindow(info->window).y -
            info->moved.y;
        move_event(info);
    }
}

void handle_event(paint_t *info)
{
    sfEvent event = info->event;
    while (sfRenderWindow_pollEvent(info->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(info->window);
            info->running = TERMINATE;
            return;
        }
        if (info->gui->prio->size != 0) {
            priority_button_event(event, info);
            return;
        }
        set_move(event, info);
        tool_event(event, info);
        zoom_event(event, info);
        layer_event(info, event);
        pencil_event(info, event, info->tools->pencil);
        update_window(event, info);
        gui_info_event(event, info);
        save_file_event(event, info);
    }
}
