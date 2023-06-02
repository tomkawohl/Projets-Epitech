/*
** EPITECH PROJECT, 2022
** new_sprite.c
** File description:
** desc
*/

#include "msl.h"
#include "../../../includes/src_struct.h"

sfSprite *ssl_new_sprite(char const *path, Vect2f scale, Vect2f pos)
{
    sfTexture *texture = sfTexture_createFromFile(path, NULL);
    sfSprite *sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, pos);
    return sprite;
}
