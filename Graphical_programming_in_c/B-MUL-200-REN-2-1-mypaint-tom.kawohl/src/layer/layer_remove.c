/*
** EPITECH PROJECT, 2022
** tools/pencil
** File description:
** layer_remove
*/
#include "my_paint.h"

int has_layer_changed(int set, int get)
{
    static int changed = false;

    if (get == true)
        return (changed);
    if (set == true)
        changed = true;
    else
        changed = false;
    return (changed);
}

void layer_remove(layer_t *layer, bool protect)
{
    layer_element_t *to_remove = NULL;

    if (!layer)
        return;
    if (protect == true && layer->size < 2)
        return;
    if (layer->first == NULL)
        return;
    to_remove = layer->first;
    layer->first = layer->first->next;
    list_texture_destroy(to_remove->list_texture);
    free(to_remove);
    layer->size--;
}

void layer_remove_all(layer_t *layer)
{
    if (!layer)
        return;
    while (layer->first != NULL && layer->size != 0) {
        layer_remove(layer, false);
    }
    return;
}
