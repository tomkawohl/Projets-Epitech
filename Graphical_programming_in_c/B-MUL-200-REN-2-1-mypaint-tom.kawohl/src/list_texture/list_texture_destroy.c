/*
** EPITECH PROJECT, 2022
** list_texture
** File description:
** list_texture_destroy
*/
#include "my_paint.h"

void list_texture_destroy(list_texture_t *list_texture)
{
    if (!list_texture)
        return;
    while (list_texture->first) {
        list_texture_remove(list_texture, false);
    }
    free(list_texture);
}
