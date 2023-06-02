/*
** EPITECH PROJECT, 2023
** map_editor
** File description:
** map_editor_tile_add_colision
*/
/**
 * @file map_editor_tile_add_colision.c
 *
 * @brief add a colision to a tile and a 'o' to map_editor
 *
 * @date 07/04/2023
*/
#include "src.h"
#include "lib_will.h"

void m_e_tile_add_colision(map_edit_t *map_edit, sfVector2i coord)
{
    if (coord.x >= map_edit->grid->limit.x
        || coord.y >= map_edit->grid->limit.y)
        return;
    if (map_edit->grid->tiles[coord.y][coord.x].solid) {
        edit_obj_remove_get(map_edit->list_col, coord);
        map_edit->grid->tiles[coord.y][coord.x].solid = false;
    } else {
        edit_obj_add(map_edit->list_col, coord, COLISION_EDIT, map_edit);
        map_edit->grid->tiles[coord.y][coord.x].solid = true;
    }
    return;
}
