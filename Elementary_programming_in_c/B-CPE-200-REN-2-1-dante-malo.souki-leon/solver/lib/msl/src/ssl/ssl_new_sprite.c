/*
** EPITECH PROJECT, 2022
** new_sprite.c
** File description:
** desc
*/

#include "msl.h"

sfSprite *ssl_new_sprite(char *name, float l, float L)
{
    sfTexture *texture = sfTexture_createFromFile(name, NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {l, L};
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    return sprite;
}
