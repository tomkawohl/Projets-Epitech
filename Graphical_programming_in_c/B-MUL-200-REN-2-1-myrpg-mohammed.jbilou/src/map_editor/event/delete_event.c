/*
** EPITECH PROJECT, 2023
** map_editor
** File description:
** delete_event
*/
/**
 * @file delete_event.c
 *
 * @brief Handle delete event
 *
 * @date 10/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include <math.h>

void delete_event(map_edit_t *map_edit, sfMouseButtonEvent *mouse)
{
    sfFloatRect bound = {0};
    sfVector2i index = {0, 0};
    sfVector2f pos = {0, 0};

    if (map_edit->state != DELETE)
        return;
    bound = sfRectangleShape_getGlobalBounds(map_edit->buttons[1].rect[0]);
    if (!sfFloatRect_contains(&bound, (float)mouse->x, (float)mouse->y))
        return;
    pos = sfRectangleShape_getPosition(map_edit->buttons[1].rect[0]);
    if (mouse->x - pos.x != 0)
        index.x = (int)((mouse->x - pos .x) / TILE_SIZE);
    if (mouse->y - pos.y != 0)
        index.y = (int)((mouse->y - pos.y) / TILE_SIZE);
    tile_destroy(map_edit->grid->tiles[index.y][index.x]);
    map_edit->grid->tiles[index.y][index.x].texture = NULL;
    map_edit->grid->tiles[index.y][index.x].sprite = NULL;
    free(map_edit->tiles_pos_set[index.y].tile_pos[index.x]);
    map_edit->tiles_pos_set[index.y].tile_pos[index.x] = NULL;
    return;
}
