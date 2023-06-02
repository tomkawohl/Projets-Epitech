/*
** EPITECH PROJECT, 2022
** obj
** File description:
** obj_sprite_create
*/
#include "../../include/w_csfml.h"

object_t *obj_sprite_create(const char *filename)
{
    object_t *obj = {0};
    obj = malloc(sizeof(object_t));
    if (!filename)
        return (NULL);
    obj->texture = sfTexture_createFromFile(filename, NULL);
    obj->sprite = sfSprite_create();
    obj->rect = (sfIntRect){0, 0, 0, 0};
    obj->speed = 0;
    obj->arr = (sfVector2f){0, 0};
    obj->dep = (sfVector2f){0, 0};
    obj->delay = 0;
    obj->hitbox = (sfIntRect){0, 0, 0, 0};
    obj->hitbox_r = NULL;
    obj->hitbox_c = NULL;
    obj->has_took_off = FALSE;
    obj->radius = 0.0;
    obj->angle = 0.0;
    obj->direction = (sfVector2f){0, 0};
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    return (obj);
}
