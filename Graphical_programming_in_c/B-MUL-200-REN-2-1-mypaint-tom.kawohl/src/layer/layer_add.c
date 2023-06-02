/*
** EPITECH PROJECT, 2022
** tools/pencil
** File description:
** layer_add
*/
#include "my_paint.h"

void layer_add(layer_t *layer, int width, int height)
{
    layer_element_t *to_add = malloc(sizeof(*to_add));

    if (to_add == NULL)
        return;
    to_add->prev = NULL;
    to_add->next = NULL;
    to_add->list_texture = list_texture_init();
    list_texture_add(to_add->list_texture, width, height);
    to_add->is_activ = true;
    layer->size++;
    if (layer->first == NULL) {
        layer->first = to_add;
        layer->end = to_add;
        return;
    }
    layer->first->prev = to_add;
    to_add->next = layer->first;
    layer->first = to_add;
}
