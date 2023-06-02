/*
** EPITECH PROJECT, 2022
** obj
** File description:
** obj_collision_c_r
*/
#include "../../include/w_csfml.h"

float clamp(float min, float value, float max)
{
    if (value < min)
        value = min;
    if (value > max)
        value = max;
    return (value);
}

int is_colliding(sfVector2f c_center, sfVector2f r_top_left,
                sfVector2f r_bot_right, float radius)
{
    sfVector2f nearest_point = {0, 0};
    nearest_point.x = clamp(r_top_left.x, c_center.x, r_bot_right.x);
    nearest_point.y = clamp(r_top_left.y, c_center.x, r_bot_right.y);
    float distance = sqrt((pow((nearest_point.x - c_center.x), 2)) +
    (pow(nearest_point.y - c_center.y, 2)));
    if (distance <= radius)
        return (TRUE);
    return (FALSE);
}

int detect_collision_c_r(object_t *obj_c, object_t *obj_r)
{
    sfVector2f c = sfCircleShape_getPosition(obj_c->hitbox_c);
    float radius = sfCircleShape_getRadius(obj_c->hitbox_c);
    sfVector2f c_center = c;
    sfVector2f r = sfRectangleShape_getPosition(obj_r->hitbox_r);
    sfVector2f r_size = sfRectangleShape_getSize(obj_r->hitbox_r);
    sfVector2f r_top_left = r;
    sfVector2f r_top_right = r;
    sfVector2f r_bot_left = r;
    sfVector2f r_bot_right = r;
    r_top_right.x += r_size.x;
    r_bot_left.y += r_size.y;
    r_bot_right.x += r_size.x;
    r_bot_right.y += r_size.y;
    c_center.x += radius;
    c_center.y += radius;
    return (is_colliding(c_center, r_top_left, r_bot_right, radius));
}
