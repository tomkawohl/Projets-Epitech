/*
** EPITECH PROJECT, 2022
** list_texture
** File description:
** list_texture_init
*/
#include "my_paint.h"

list_texture_t *list_texture_init(void)
{
    list_texture_t *list_texture = NULL;

    list_texture = malloc(sizeof(*list_texture));
    if (list_texture == NULL)
        return (NULL);
    list_texture->size = 0;
    list_texture->first = NULL;
    list_texture->end = NULL;
    return (list_texture);
}
