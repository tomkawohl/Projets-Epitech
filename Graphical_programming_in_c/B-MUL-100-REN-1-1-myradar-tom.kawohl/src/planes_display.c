/*
** EPITECH PROJECT, 2022
** src
** File description:
** planes_display
*/
#include "src.h"

void plane_display(sfRenderWindow *win, object_t **planes,
                    w_event_t w_event, int i)
{
    if (w_event.display_hitbox == TRUE)
        sfRenderWindow_drawRectangleShape(win, planes[i]->hitbox_r, NULL);
    if (w_event.display_sprite == TRUE)
        sfRenderWindow_drawSprite(win, planes[i]->sprite, NULL);
}

/* return if simulation must end */
int planes_display(sfRenderWindow *win, object_t **planes, w_event_t w_event)
{
    int i = 0;
    int is_end = FALSE;
    int plane_end = 0;
    while (planes[i] != NULL) {
        if (planes[i]->is_crashed == FALSE && planes[i]->has_landed == FALSE &&
        planes[i]->has_took_off == TRUE) {
            plane_display(win, planes, w_event, i);
        }
        if (planes[i]->is_crashed == TRUE || planes[i]->has_landed == TRUE)
            plane_end++;
        i++;
    }
    if (plane_end == i)
        is_end = TRUE;
    return (is_end);
}
