/*
** EPITECH PROJECT, 2022
** tools/pencil
** File description:
** pencil_draw
*/
#include "my_paint.h"

void pencil_draw(paint_t *info)
{
    list_element_texture_t *texture = NULL;

    sfTexture_updateFromPixels(
        info->tools->pencil->current_layer->list_texture->first->texture,
        info->tools->pencil->pixels, WIDTH, HEIGHT, 0, 0);
    texture = info->tools->pencil->current_layer->list_texture->first;
    while (texture) {
        if (texture->is_activ == true)
            sfRenderWindow_drawSprite(info->window, texture->sprite, NULL);
        texture = texture->next;
    }
}
