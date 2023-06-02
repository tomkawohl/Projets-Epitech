/*
** EPITECH PROJECT, 2022
** tools/pencil
** File description:
** layer_draw
*/
#include "my_paint.h"
/*
void layer_draw_element(paint_t *info, layer_element_t *layer)
{
    list_element_texture_t *texture = NULL;

    if (layer == NULL)
        return;
    texture = layer->list_texture->first;
    while (texture) {
        if (texture->is_activ == true)
            sfRenderWindow_drawSprite(info->window, texture->sprite, NULL);
        texture = texture->next;
    }
    return;
}
*/

void layer_draw_cut(paint_t *info, list_element_texture_t * texture)
{
    sfSprite_setScale(texture->sprite, (sfVector2f)
        {get_scale((float) WIDTH, (float) info->window_size.x, (float) WIDTH)
        * info->window_zoom, get_scale((float) HEIGHT, (float)
        info->window_size.y, (float) HEIGHT) * info->window_zoom});
    sfRenderWindow_drawSprite(info->window, texture->sprite, NULL);
}

void layer_draw_element(paint_t *info, layer_element_t *layer)
{
    list_element_texture_t *texture = NULL;
    unsigned int j = 0;

    if (layer == NULL)
        return;
    texture = layer->list_texture->end;
    while (texture && j < layer->list_texture->size) {
        if (texture->is_activ == true) {
            layer_draw_cut(info, texture);
        }
        texture = texture->prev;
        j++;
    }
    return;
}

void layer_draw(paint_t *info)
{
    layer_element_t *layer = NULL;
    unsigned int i = 0;

    if (info->layer->end == NULL)
        return;
    layer = info->layer->end;
    while (layer && i < info->layer->size) {
        if (layer->is_activ == true)
            layer_draw_element(info, layer);
        layer = layer->prev;
        i++;
    }
    return;
}

/*
void layer_draw(paint_t *info)
{
    layer_element_t *layer = NULL;

    if (info->layer->first == NULL)
        return;
    layer = info->layer->first;
    while (layer) {
        if (layer->is_activ == true)
            layer_draw_element(info, layer);
        layer = layer->next;
    }
    return;
}
*/
