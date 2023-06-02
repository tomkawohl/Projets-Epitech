/*
** EPITECH PROJECT, 2022
** tools/pencil
** File description:
** layer_init
*/
#include "my_paint.h"

layer_t *layer_init(int width, int height)
{
    layer_t *layer = malloc(sizeof(*layer));

    if (layer == NULL)
        return (NULL);
    layer->size = 0;
    layer->first = NULL;
    layer->end = NULL;
    layer_add(layer, width, height);
    return (layer);
}
