/*
** EPITECH PROJECT, 2023
** map_editor/tile
** File description:
** tile_pos_set_init
*/
/**
 * @file tile_pos_set_init.c
 *
 * @brief Init a struct tile_pos_set
 *
 * @date 10/04/2023
*/
#include "src.h"
#include "lib_will.h"

tile_pos_set_t *tile_pos_set_init(sfVector2i limit)
{
    tile_pos_set_t *tile_pos = malloc(sizeof(*tile_pos) * limit.y);

    if (!verify_malloc(tile_pos, "tile_pos_set_init"))
        return (NULL);
    for (u_int i = 0; i < limit.y; i++) {
        tile_pos[i].tile_pos = malloc(sizeof(char **) * (limit.x));
        for (u_int j = 0; j < limit.x; j++) {
            tile_pos[i].tile_pos[j] = NULL;
        }
    }
    return (tile_pos);
}
