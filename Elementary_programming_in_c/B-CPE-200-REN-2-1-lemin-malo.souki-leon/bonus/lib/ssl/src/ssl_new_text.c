/*
** EPITECH PROJECT, 2022
** new_sprite.c
** File description:
** desc
*/

#include "msl.h"

sfText *ssl_new_text(sfFont *font, Vect2f scale, Vect2f pos, char *str)
{
    sfText *text = sfText_create();

    sfText_setFont(text, font);
    sfText_setScale(text, scale);
    sfText_setPosition(text, pos);
    sfText_setColor(text, sfBlack);
    sfText_setString(text, str);
    return text;
}
