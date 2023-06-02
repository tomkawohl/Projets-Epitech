/*
** EPITECH PROJECT, 2022
** tools/pencil
** File description:
** pencil_destroy
*/
#include "my_paint.h"

void pencil_destroy(pencil_t *pencil)
{
    free(pencil->pixels);
    sfVertexArray_destroy(pencil->lines);
    free(pencil);
}
