/*
** EPITECH PROJECT, 2022
** list_texture
** File description:
** list_texture_add
*/
#include "my_paint.h"

void list_texture_add(list_texture_t *list_texture, int width, int height)
{
    list_element_texture_t *to_add = malloc(sizeof(*to_add));

    if (to_add == NULL)
        return;
    to_add->texture = sfTexture_create(width, height);
    to_add->sprite = sfSprite_create();
    sfSprite_setTexture(to_add->sprite, to_add->texture, sfTrue);
    to_add->index = list_texture->size;
    to_add->is_activ = true;
    to_add->next = NULL;
    to_add->prev = NULL;
    list_texture->size++;
    if (list_texture->first == NULL) {
        list_texture->first = to_add;
        list_texture->end = to_add;
        return;
    }
    list_texture->first->prev = to_add;
    to_add->next = list_texture->first;
    list_texture->first = to_add;
}
