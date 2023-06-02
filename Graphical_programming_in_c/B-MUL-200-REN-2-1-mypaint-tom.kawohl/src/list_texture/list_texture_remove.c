/*
** EPITECH PROJECT, 2022
** list_texture
** File description:
** list_texture_remove
*/
#include "my_paint.h"

void list_texture_remove(list_texture_t *list_texture, bool protect)
{
    list_element_texture_t *to_remove = NULL;

    if (!list_texture)
        return;
    if (list_texture->size < 2 && protect == true)
        return;
    if (list_texture == NULL)
        return;
    to_remove = list_texture->first;
    list_texture->first = list_texture->first->next;
    sfSprite_destroy(to_remove->sprite);
    sfTexture_destroy(to_remove->texture);
    free(to_remove);
    list_texture->size--;
}
