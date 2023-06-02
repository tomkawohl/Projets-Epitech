/*
** EPITECH PROJECT, 2022
** src
** File description:
** debug_display
*/
#include "../src.h"

void debug_display(sfRenderWindow *win, object_t **planes, object_t **towers)
{
    for (int i = 0; planes[i] != NULL; i++) {
        if (planes[i]->hitbox_r != NULL)
            sfRenderWindow_drawRectangleShape(win, planes[i]->hitbox_r, NULL);
        if (planes[i]->sprite != NULL)
            sfRenderWindow_drawSprite(win, planes[i]->sprite, NULL);
    }
    if (towers[0]->hitbox_c != NULL)
        sfRenderWindow_drawCircleShape(win, towers[0]->hitbox_c, NULL);
    if (towers[0]->sprite != NULL)
        sfRenderWindow_drawSprite(win, towers[0]->sprite, NULL);
}
