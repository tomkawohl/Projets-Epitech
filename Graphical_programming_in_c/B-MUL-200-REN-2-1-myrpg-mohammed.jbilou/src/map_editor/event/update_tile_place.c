/*
** EPITECH PROJECT, 2023
** map_editor
** File description:
** update_tile_place
*/
/**
 * @file update_tile_place.c
 *
 * @brief Update tile place
 *
 * @date 10/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include <math.h>

void update_tile_place(map_edit_t *map_edit, sfMouseMoveEvent *mouse)
{
    sfFloatRect bound =
        sfRectangleShape_getGlobalBounds(map_edit->buttons[1].rect[0]);
    sfVector2f cursor_pos = {0, 0};

    if (!sfFloatRect_contains(&bound, (float)mouse->x, (float)mouse->y))
        return;
    cursor_pos = sfSprite_getPosition(map_edit->tile_place.sprite);
    if (cursor_pos.x > mouse->x) {
        cursor_pos.x -= TILE_SIZE;
    } else {
        if ((fabs)(cursor_pos.x - mouse->x) >= TILE_SIZE)
            cursor_pos.x += TILE_SIZE;
    }
    if (cursor_pos.y > mouse->y) {
        cursor_pos.y -= TILE_SIZE;
    } else {
        if ((fabs)(cursor_pos.y - mouse->y) >= TILE_SIZE)
            cursor_pos.y += TILE_SIZE;
    }
    sfSprite_setPosition(map_edit->tile_place.sprite, cursor_pos);
}
