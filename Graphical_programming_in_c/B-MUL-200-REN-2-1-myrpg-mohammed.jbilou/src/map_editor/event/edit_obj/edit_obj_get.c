/*
** EPITECH PROJECT, 2023
** map_editor
** File description:
** edit_obj_get
*/
/**
 * @file edit_obj_get.c
 *
 * @brief get an element edit_obj
 *
 * @date 07/04/2023
*/
#include "src.h"
#include "lib_will.h"

edit_object_t *edit_obj_get(list_edit_obj_t *list, sfVector2i coord)
{
    edit_object_t *find = NULL;

    if (!list)
        return (NULL);
    find = list->first;
    while (find) {
        if (find->pos.x == coord.x && find->pos.y == coord.y)
            return (find);
        find = find->next;
    }
    return (NULL);
}
