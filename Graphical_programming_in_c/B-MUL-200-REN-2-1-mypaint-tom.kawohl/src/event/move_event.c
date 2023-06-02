/*
** EPITECH PROJECT, 2023
** src/event/handle_event
** File description:
** moving of all in canvas and canvas events
*/

#include "my_paint.h"

void move_texture(paint_t *info, list_element_texture_t * texture)
{
    sfSprite_move(texture->sprite, info->moved);
}

void move_layer_element(paint_t *info, layer_element_t *layer)
{
    list_element_texture_t *texture = NULL;
    unsigned int j = 0;

    if (layer == NULL)
        return;
    texture = layer->list_texture->end;
    while (texture && j < layer->list_texture->size) {
        if (texture->is_activ == true) {
            move_texture(info, texture);
        }
        texture = texture->prev;
        j++;
    }
    return;
}

void move_layer(paint_t *info)
{
    layer_element_t *layer = NULL;
    unsigned int i = 0;

    if (info->layer->end == NULL)
        return;
    layer = info->layer->end;
    while (layer && i < info->layer->size) {
        if (layer->is_activ == true)
            move_layer_element(info, layer);
        layer = layer->prev;
        i++;
    }
    return;
}

void move_canvas(paint_t *info)
{
    sfRectangleShape_move(info->canvas->rect, info->moved);
    info->canvas->perim->top += info->moved.y;
    info->canvas->perim->left += info->moved.x;
    sfRenderWindow_drawRectangleShape(info->window, info->canvas->rect, NULL);
}

void move_event(paint_t *info)
{
    move_layer(info);
    move_canvas(info);
}
