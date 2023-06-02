/*
** EPITECH PROJECT, 2023
** map_editor
** File description:
** update_selected
*/
/**
 * @file update_selected.c
 *
 * @brief Update selected tile on set
 *
 * @date 10/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include <math.h>

void update_selected(map_edit_t *map_edit, sfMouseButtonEvent *mouse)
{
    sfFloatRect set_bound = sfSprite_getGlobalBounds(map_edit->set_sprite);
    sfVector2i pos = {0, 0};
    sfVector2i index = {0, 0};

    if (!sfFloatRect_contains(&set_bound, (float)mouse->x, (float)mouse->y))
        return;
    pos.x = mouse->x;
    pos.y = (float)mouse->y;
    while (pos.x % 48 != 0 && pos.x > 0)
        pos.x--;
    while ((pos.y - SET_POS_Y) % 48 != 0 && pos.y > 0)
        pos.y--;
    index.x = (int)((mouse->x - set_bound .left) / TILE_SIZE);
    index.y = (int)((mouse->y - set_bound .top) / TILE_SIZE);
    map_edit->tile_coord_select = index;
    sfSprite_setPosition(map_edit->selected.sprite, (sfVector2f){pos.x, pos.y});
}
