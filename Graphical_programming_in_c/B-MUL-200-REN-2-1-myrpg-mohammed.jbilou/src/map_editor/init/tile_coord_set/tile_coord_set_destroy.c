/*
** EPITECH PROJECT, 2023
** map_editor/tile_coord_set
** File description:
** tile_coord_set_destroy
*/
/**
 * @file tile_coord_set_destroy.c
 *
 * @brief Destroy a list of tile_coord
 *
 * @date 09/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "tile_coord_set.h"

void tile_coord_set_destroy(tile_coord_set_t *list)
{
    if (!list)
        return;
    while (list->first != NULL) {
        tile_coord_set_remove(list);
    }
    free(list);
    return;
}
