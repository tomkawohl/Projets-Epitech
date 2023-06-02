/*
** EPITECH PROJECT, 2022
** list_texture
** File description:
** list_texture_remove_unactiv
*/
#include "my_paint.h"

void list_texture_update_index(list_texture_t *list_texture)
{
    unsigned int i = 0;
    list_element_texture_t *node = NULL;

    if (!list_texture)
        return;
    while (node) {
        node->index = i;
        i++;
        node = node->next;
    }
    return;
}

void list_texture_remove_node(list_texture_t *list_texture,
    list_element_texture_t *node)
{
    list_texture->size--;
    if (list_texture->first == node)
        list_texture->first = node->next;
    if (list_texture->end == node)
        list_texture->end = node->prev;
    if (node->prev != NULL)
        node->prev->next = node->next;
    if (node->next != NULL)
        node->next->prev = node->prev;
    node->next = NULL;
    node->prev = NULL;
    sfSprite_destroy(node->sprite);
    sfTexture_destroy(node->texture);
    free(node);
}

void list_texture_remove_unactiv(list_texture_t *list_texture)
{
    list_element_texture_t *node = NULL;

    if (!list_texture)
        return;
    node = list_texture->first;
    while (node && node->next) {
        if (node->is_activ == false) {
            list_texture_remove_node(list_texture, node);
            node = list_texture->first;
        }
        node = node->next;
    }
    return;
}
