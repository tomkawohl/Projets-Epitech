/*
** EPITECH PROJECT, 2023
** map_editor
** File description:
** update_colision
*/
/**
 * @file update_colision.c
 *
 * @brief Update colision of the new map open
 *
 * @date 08/04/2023
*/
#include "src.h"
#include "lib_will.h"

void m_e_tile_update_colision(map_edit_t *map_edit, sfVector2i coord)
{
    if (coord.x >= map_edit->grid->limit.x
        || coord.y >= map_edit->grid->limit.y)
        return;
    edit_obj_add(map_edit->list_col, (sfVector2i){coord.y, coord.x},
        COLISION_EDIT, map_edit);
    return;
}

static void add_colision(map_edit_t *map_edit, tile_t tile, int i, int j)
{
    if (tile.solid == 1)
        m_e_tile_update_colision(map_edit, (sfVector2i){i, j});
    return;
}

void update_colision(map_edit_t *map_edit)
{
    edit_obj_clear(map_edit->list_col);
    for (u_int i = 0; i < map_edit->grid->limit.y; i++) {
        for (u_int j = 0; j < map_edit->grid->limit.y; j++) {
            add_colision(map_edit, map_edit->grid->tiles[i][j], i, j);
        }
    }
    return;
}
