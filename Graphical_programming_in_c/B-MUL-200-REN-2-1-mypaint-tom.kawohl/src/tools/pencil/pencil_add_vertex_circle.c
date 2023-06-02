/*
** EPITECH PROJECT, 2022
** tools/pencil
** File description:
** pencil_add_vertex_circle
*/
#include "my_paint.h"

void put_pixel_circle(pencil_t *pencil, int i, int j, int k)
{
    int index = 0;
    int x = (int)(pencil->pos.x + i + k);
    int y = (int)(pencil->pos.y + j);
    float distance = 0.0f;

    if (x >= 0 && x < pencil->limit.x && y >= 0 && y < pencil->limit.y) {
        distance = sqrtf((float)(k * k + j * j));
        if (distance <= (float) pencil->size) {
            index = ((y * pencil->limit.x + x) * 4);
            pencil->pixels[index + 0] = pencil->color.r;
            pencil->pixels[index + 1] = pencil->color.g;
            pencil->pixels[index + 2] = pencil->color.b;
            pencil->pixels[index + 3] = pencil->color.a;
        }
    }
}

void pencil_add_vertex_circle(pencil_t *pencil, int i)
{
    for (register int j = (-pencil->size); j <= pencil->size; j++) {
        for (register int k = (-pencil->size); k <= pencil->size; k++) {
            put_pixel_circle(pencil, i, j, k);
        }
    }
}
