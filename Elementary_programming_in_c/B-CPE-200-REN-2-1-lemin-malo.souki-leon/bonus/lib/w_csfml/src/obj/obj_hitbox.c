/*
** EPITECH PROJECT, 2022
** obj
** File description:
** obj_hitbox
*/
#include "../../include/w_csfml.h"

obj_hitbox_t obj_get_hitbox(object_t *obj)
{
    obj_hitbox_t obj_hitbox;
    obj_hitbox.get_pos = sfSprite_getPosition(obj->sprite);
    obj_hitbox.get_hitbox = obj->hitbox;
    return (obj_hitbox);
}

sfRectangleShape *hitbox_rect(obj_hitbox_t obj_hitbox)
{
    sfRectangleShape *hitbox_r = sfRectangleShape_create();
    sfVector2f size = {(float)obj_hitbox.get_hitbox.width,
    (float)obj_hitbox.get_hitbox.height};
    sfRectangleShape_setPosition(hitbox_r, obj_hitbox.get_pos);
    sfRectangleShape_setFillColor(hitbox_r, sfTransparent);
    sfRectangleShape_setOutlineColor(hitbox_r, sfRed);
    sfRectangleShape_setOutlineThickness(hitbox_r, 2.0);
    sfRectangleShape_setSize(hitbox_r, size);
    return (hitbox_r);
}

sfCircleShape *hitbox_circle(object_t *obj, float radius)
{
    sfVector2f pos = sfSprite_getPosition(obj->sprite);
    pos.x += (float)(obj->hitbox.width / 2);
    pos.y += (float)(obj->hitbox.height / 2);
    pos.x -= radius;
    pos.y -= radius;
    sfCircleShape *hitbox_c = sfCircleShape_create();
    sfCircleShape_setRadius(hitbox_c, radius);
    sfCircleShape_setPosition(hitbox_c, pos);
    sfCircleShape_setOutlineColor(hitbox_c, sfRed);
    sfCircleShape_setOutlineThickness(hitbox_c, 2.0);
    sfCircleShape_setFillColor(hitbox_c, sfTransparent);
    return (hitbox_c);
}
