/*
** EPITECH PROJECT, 2022
** src
** File description:
** matrix
*/
#include "src.h"

matrix_t matrix_rotation(float angle)
{
    float rad = angle * 3.14 / 180;
    matrix_t rot = {0};
    rot.a = cos(rad);
    rot.b = -(sin(rad));
    rot.c = 0;
    rot.d = sin(rad);
    rot.e = cos(rad);
    rot.f = 0;
    rot.g = 0;
    rot.h = 0;
    rot.i = 1;
    return (rot);
}

sfVector2f transform_points(sfVector2f points, matrix_t rot)
{
    sfVector2f res = {0, 0};
    res.x = rot.a * points.x + rot.b * points.y + rot.c * 1;
    res.y = rot.d * points.x + rot.e * points.y + rot.f * 1;
    return (res);
}
