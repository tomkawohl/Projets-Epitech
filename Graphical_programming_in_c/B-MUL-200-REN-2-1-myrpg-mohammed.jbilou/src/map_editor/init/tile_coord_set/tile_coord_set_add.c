/*
** EPITECH PROJECT, 2023
** map_editor/tile_coord_set
** File description:
** tile_coord_set_add
*/
/**
 * @file tile_coord_set_add.c
 *
 * @brief Add an element to a list tile_coord_set
 *
 * @date 09/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "tile_coord_set.h"

void tile_coord_set_add(tile_coord_set_t *list, u_int x, u_int y,
    u_int nb_set)
{
    tile_coord_set_element_t *to_add = malloc(sizeof(*to_add));

    if (!verify_malloc(to_add, "tile_coord_set_add"))
        return;
    to_add->nb_set = nb_set;
    to_add->x = x;
    to_add->y = y;
    list->size++;
    to_add->next = NULL;
    if (list->first == NULL)
        list->first = to_add;
    else {
        to_add->next = list->first;
        list->first = to_add;
    }
    return;
}
