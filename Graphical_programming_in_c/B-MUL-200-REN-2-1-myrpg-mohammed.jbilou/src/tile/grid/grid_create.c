/*
** EPITECH PROJECT, 2023
** tile
** File description:
** grid_create
*/
/**
 * @file grid_create.c
 *
 * @brief Create a grid
 *
 * @date 05/04/2023
*/
#include "tile.h"
#include "lib_will.h"

static tile_t *grid_init_width(u_int width, u_int i, sfVector2f pos)
{
    tile_t *tile = malloc(sizeof(*tile) * (width + 1));

    if (!verify_malloc(tile, "grid_init_width\n"))
        return (NULL);
    for (u_int j = 0; j < width; j++) {
        tile[j] = tile_create(pos);
        pos.x += TILE_SIZE;
    }
    tile[width].is_end = true;
    return (tile);
}

static tile_t **grid_init_tiles(u_int width, u_int height, sfVector2f pos)
{
    tile_t **tiles = malloc(sizeof(*tiles) * (height + 1));

    if (!verify_malloc(tiles, "grid_create : tiles"))
        return (NULL);
    for (u_int i = 0; i < height; i++) {
        tiles[i] = grid_init_width(width, i, pos);
        if (!verify_malloc(tiles[i], "grid_create"))
            return (NULL);
        pos.y += TILE_SIZE;
    }
    tiles[height] = NULL;
    return (tiles);
}

static map_t **grid_init_map(u_int width, u_int height)
{
    map_t **map = malloc(sizeof(*map) * (height + 1));

    if (!verify_malloc(map, "grid_create : map"))
        return (NULL);
    for (u_int i = 0; i < height; i++) {
        map[i] = malloc(sizeof(map_t) * width);
        if (!verify_malloc(map[i], "grid_create : map[i]"))
            return (NULL);
        for (u_int j = 0; j < width; j++)
            map[i][j].tiles = NULL;
    }
    return (map);
}

grid_t *grid_create(unsigned int width, unsigned int height, sfVector2f pos)
{
    grid_t *grid = malloc(sizeof(*grid));

    if (!verify_malloc(grid, "grid_create : grid"))
        return (NULL);
    grid->tiles = grid_init_tiles(width, height, pos);
    grid->pos = pos;
    grid->limit.x = width;
    grid->limit.y = height;
    return (grid);
}
