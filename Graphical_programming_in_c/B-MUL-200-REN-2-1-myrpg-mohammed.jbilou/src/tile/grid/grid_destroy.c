/*
** EPITECH PROJECT, 2023
** tile
** File description:
** grid_destroy
*/
/**
 * @file grid_destroy.c
 *
 * @brief Destroy a grid
 *
 * @date 05/04/2023
*/
#include "tile.h"
#include "lib_will.h"

static void grid_destroy_tiles(tile_t **tiles)
{
    for (u_int i = 0; tiles[i] != NULL; i++) {
        for (u_int j = 0; tiles[i][j].is_end != true; j++)
            tile_destroy(tiles[i][j]);
        free(tiles[i]);
    }
    free(tiles);
}

static void free_map_tiles(map_t *map, u_int limit)
{
    for (u_int i = 0; i < limit; i++) {
        if (map[i].tiles != NULL)
            free(map[i].tiles);
    }
    free(map);
}

void grid_destroy(grid_t *grid)
{
    if (grid == NULL)
        return;
    grid_destroy_tiles(grid->tiles);
    free(grid);
    grid = NULL;
    return;
}

/*
static void grid_destroy_map(grid_t *grid)
{
    if (grid->map == NULL)
        return;
    for (u_int i = 0; i < grid->limit.y; i++) {
        if (grid->map[i] != NULL)
            free_map_tiles(grid->map[i], grid->limit.x);
    }
    free(grid->map);
}
*/
