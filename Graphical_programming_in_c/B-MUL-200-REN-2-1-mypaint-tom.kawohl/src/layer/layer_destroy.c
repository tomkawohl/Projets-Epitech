/*
** EPITECH PROJECT, 2022
** layer
** File description:
** layer_destroy
*/
#include "my_paint.h"

void layer_destroy(layer_t *layer)
{
    if (!layer)
        return;
    while (layer->first) {
        layer_remove(layer, false);
    }
    free(layer);
}
