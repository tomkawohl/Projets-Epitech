/*
** EPITECH PROJECT, 2023
** map_editor
** File description:
** map_editor_col_event
*/
/**
 * @file map_editor_col_event.c
 *
 * @brief Handle map editor col event
 *
 * @date 07/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include <math.h>

void map_editor_col_event(map_edit_t *map_edit, sfMouseButtonEvent *mouse)
{
    sfFloatRect bound = {0};
    sfVector2f pos = {0, 0};
    sfVector2i coord = {0, 0};

    if (map_edit->state != COLLISION)
        return;
    bound = sfRectangleShape_getGlobalBounds(map_edit->buttons[1].rect[0]);
    if (!sfFloatRect_contains(&bound, (float)mouse->x, (float)mouse->y))
        return;
    pos = sfRectangleShape_getPosition(map_edit->buttons[1].rect[0]);
    if (mouse->x - pos.x != 0)
        coord.x = (int)((mouse->x - pos .x) / TILE_SIZE);
    if (mouse->y - pos.y != 0)
        coord.y = (int)((mouse->y - pos.y) / TILE_SIZE);
    m_e_tile_add_colision(map_edit, (sfVector2i){coord.x, coord.y});
    return;
}
