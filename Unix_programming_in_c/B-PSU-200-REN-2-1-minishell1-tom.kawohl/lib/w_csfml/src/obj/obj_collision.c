/*
** EPITECH PROJECT, 2022
** obj
** File description:
** obj_collision
*/
#include "../../include/w_csfml.h"

int detect_collision_circle(object_t *obj1, object_t *obj2)
{
    sfVector2f C = sfCircleShape_getPosition(obj1->hitbox_c);
    sfVector2f D = sfCircleShape_getPosition(obj2->hitbox_c);
    float Cr = sfCircleShape_getRadius(obj1->hitbox_c);
    float Dr = sfCircleShape_getRadius(obj2->hitbox_c);
    if ((pow((double)C.x - (double)D.x, 2)) +
    (pow((double)C.y - (double)D.y, 2)) <= (pow(Cr + Dr, 2)))
        return (TRUE);
    return (FALSE);
}
