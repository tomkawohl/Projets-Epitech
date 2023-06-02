/*
** EPITECH PROJECT, 2023
** tile
** File description:
** grid_draw
*/
/**
 * @file grid_draw.c
 *
 * @brief Draw all the tiles who have texture of a grid
 *
 * @date 05/04/2023
*/
#include "tile.h"
#include "lib_will.h"

static void draw_tile(sfRenderWindow *window, tile_t tile)
{
    if (tile.sprite != NULL)
        sfRenderWindow_drawSprite(window, tile.sprite, NULL);
}

void grid_draw(sfRenderWindow *window, tile_t **grid)
{
    for (register u_int i = 0; grid[i] != NULL; i++) {
        for (register u_int j = 0; grid[i][j].is_end != true; j++) {
            draw_tile(window, grid[i][j]);
        }
    }
    return;
}
