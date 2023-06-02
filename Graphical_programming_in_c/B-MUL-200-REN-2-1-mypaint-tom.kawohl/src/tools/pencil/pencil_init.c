/*
** EPITECH PROJECT, 2022
** tools/pencil
** File description:
** pencil_init
*/
#include "my_paint.h"

pencil_t *pencil_init(U_INT width, U_INT height, layer_t *layer)
{
    pencil_t *pencil = NULL;

    pencil = malloc(sizeof(*pencil));
    pencil->pixels = malloc(sizeof(sfUint8) * width * height * 4);
    pencil->current_layer = layer->first;
    pencil->vertex.color = sfWhite;
    pencil->lines = sfVertexArray_create();
    pencil->size = 10;
    pencil->is_activ = false;
    pencil->limit.x = width;
    pencil->limit.y = height;
    pencil->color = sfBlack;
    pencil->is_drawing = false;
    pencil->is_eraser = false;
    pencil->form = SQUARE;
    return (pencil);
}
