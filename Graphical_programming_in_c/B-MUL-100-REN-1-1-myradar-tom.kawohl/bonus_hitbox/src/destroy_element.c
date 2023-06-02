/*
** EPITECH PROJECT, 2022
** src
** File description:
** free_element
*/
#include "src.h"

void obj_destroy_all(object_t **obj)
{
    if (obj == NULL)
        return;
    for (int i = 0; obj[i] != NULL; i++) {
        obj_destroy(obj[i]);
    }
    free (obj);
}
