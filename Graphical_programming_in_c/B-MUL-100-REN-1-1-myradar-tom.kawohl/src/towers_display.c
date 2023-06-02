/*
** EPITECH PROJECT, 2022
** src
** File description:
** towers_display
*/
#include "src.h"

void tower_display(sfRenderWindow *win, object_t **towers,
                    w_event_t w_event, int i)
{
    if (w_event.display_hitbox == TRUE)
        sfRenderWindow_drawCircleShape(win, towers[i]->hitbox_c, NULL);
    if (w_event.display_sprite == TRUE)
        sfRenderWindow_drawSprite(win, towers[i]->sprite, NULL);
}

void towers_displays(sfRenderWindow *win, object_t **towers, w_event_t w_event)
{
    if (towers == NULL)
        return;
    int i = 0;
    while (towers[i] != NULL) {
        tower_display(win, towers, w_event, i);
        i++;
    }
}
