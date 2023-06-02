/*
** EPITECH PROJECT, 2023
** map_editor/tile_coord_set
** File description:
** tile_coord_set_create
*/
/**
 * @file tile_coord_set_create.c
 *
 * @brief Create a list tile_coord_set
 *
 * @date 09/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "tile_coord_set.h"

tile_coord_set_t *tile_coord_set_create(void)
{
    tile_coord_set_t *list = malloc(sizeof(*list));

    if (!verify_malloc(list, "tile_set_create"))
        return (NULL);
    list->first = NULL;
    list->size = 0;
    return (list);
}
