/*
** EPITECH PROJECT, 2022
** list_texture
** File description:
** list_texture_set_activ
*/
#include "my_paint.h"

void list_texture_set_activ(list_texture_t *list_texture, U_INT activ,
U_INT index)
{
    list_element_texture_t *node = list_texture->first;
    U_INT find_node = 0;
    while (node != NULL && find_node != index) {
        find_node++;
        node = node->next;
    }
    if (node)
        node->is_activ = activ;
    return;
}
