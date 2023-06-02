/*
** EPITECH PROJECT, 2023
** map_editor
** File description:
** map_editor_update_grid
*/
/**
 * @file map_editor_update_grid.c
 *
 * @brief Place a tile in the grid if user click on canva
 *
 * @date 06/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include <math.h>

void map_editor_update_grid(map_edit_t *map_edit, sfMouseButtonEvent *mouse)
{
    sfFloatRect bound = {0};
    sfVector2i index = {0, 0};
    sfVector2f pos = {0, 0};

    if (map_edit->state != ADD)
        return;
    bound = sfRectangleShape_getGlobalBounds(map_edit->buttons[1].rect[0]);
    if (!sfFloatRect_contains(&bound, (float)mouse->x, (float)mouse->y))
        return;
    pos = sfRectangleShape_getPosition(map_edit->buttons[1].rect[0]);
    if (mouse->x - pos.x != 0)
        index.x = (int)((mouse->x - pos .x) / TILE_SIZE);
    if (mouse->y - pos.y != 0)
        index.y = (int)((mouse->y - pos.y) / TILE_SIZE);
    tile_set(map_edit->grid, (info_tile_t){map_edit->set_nb,
        map_edit->tile_coord_select}, (sfVector2i){index.y, index.x});
    tile_pos_set_add(map_edit->tiles_pos_set, (info_tile_t){map_edit->set_nb,
        map_edit->tile_coord_select},
            (sfVector2i){index.x, index.y}, map_edit->grid->limit);
}
