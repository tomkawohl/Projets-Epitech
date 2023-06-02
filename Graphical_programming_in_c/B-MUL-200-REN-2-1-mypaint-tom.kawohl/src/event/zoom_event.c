/*
** EPITECH PROJECT, 2023
** src/event/zoom_event
** File description:
** handles to scroll wheel event to zoom
*/

#include "my_paint.h"

void zoom_event(sfEvent event, paint_t *info)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyK) {
        info->origin_status = ZOOM;
        info->window_zoom += 0.1;
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyL) {
        info->origin_status = ZOOM;
        info->window_zoom -= 0.1;
    }
}
