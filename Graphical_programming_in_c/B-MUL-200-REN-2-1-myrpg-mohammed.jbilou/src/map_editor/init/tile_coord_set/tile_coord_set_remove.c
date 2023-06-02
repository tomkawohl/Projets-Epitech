/*
** EPITECH PROJECT, 2023
** map_editor/tile_coord_set
** File description:
** tile_coord_set_remove
*/
/**
 * @file tile_coord_set_remove.c
 *
 * @brief Remove an element to a list tile_coord_set
 *
 * @date 09/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "tile_coord_set.h"

void tile_coord_set_remove(tile_coord_set_t *list)
{
    tile_coord_set_element_t *to_remove = NULL;

    if (!list)
        return;
    if (list->first == NULL)
        return;
    to_remove = list->first;
    list->first = list->first->next;
    to_remove->next = NULL;
    free(to_remove);
    to_remove = NULL;
    list->size--;
    return;
}
