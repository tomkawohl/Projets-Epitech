/*
** EPITECH PROJECT, 2023
** map_editor/tile_coord_set
** File description:
** grid_tile_coord_set_init
*/
/**
 * @file grid_tile_coord_set_init.c
 *
 * @brief Create a grid_tile_coord_set of tile_coord_set
 *
 * @date 09/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "tile_coord_set.h"

grid_tile_coord_set_t *grid_tile_coord_set_init(sfVector2i limit)
{
    grid_tile_coord_set_t *grid_coord = malloc(sizeof(*grid_coord) * limit.y);

    if (!verify_malloc(grid_coord, "grid_coord_set"))
        return (NULL);
    for (u_int i = 0; i < limit.y; i++) {
        w_printf("i = %d\n", i);
        grid_coord[i].tile_coord =
            malloc(sizeof(tile_coord_set_t **) * limit.x);
        for (u_int j = 0; j < limit.x; j++)
            grid_coord[i].tile_coord[j] = NULL;
    }
    w_printf("good\n");
    return (grid_coord);
}
