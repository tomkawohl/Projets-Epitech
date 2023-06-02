/*
** EPITECH PROJECT, 2023
** map_editor
** File description:
** event/handle_view_event.c
*/
/**
 * @file handle_view_event.c
 *
 * @brief Change view when user move with Z, Q, S, D
 *
 * @date 14/04/2023
*/
#include "src.h"
#include "lib_will.h"

static void move_tile(tile_t tile)
{
    if (tile.sprite == NULL)
        return;
    sfSprite_setPosition(tile.sprite, tile.position);
}

static void move_col(map_edit_t *map_edit, sfVector2f move)
{
    edit_object_t *elem = NULL;
    sfVector2f pos = {0, 0};
    if (map_edit->list_col == NULL)
        return;
    if (map_edit->list_col->first == NULL)
        return;
    elem = map_edit->list_col->first;
    while (elem) {
        pos = sfSprite_getPosition(elem->sprite);
        pos.x += move.x;
        pos.y += move.y;
        sfSprite_setPosition(elem->sprite, pos);
        elem = elem->next;
    }
}

static void move_unit(map_edit_t *map_edit, sfVector2f move)
{
    game_unit_t *elem = NULL;
    sfVector2f pos = {0, 0};

    if (map_edit->units == NULL)
        return;
    if (map_edit->units->first == NULL)
        return;
    elem = map_edit->units->first;
    while (elem) {
        elem->pos.x += move.x;
        elem->pos.y += move.y;
        sfSprite_setPosition(elem->sprite, elem->pos);
        elem = elem->next;
    }
    return;
}

static void move_view(map_edit_t *map_edit, sfVector2f move)
{
    sfVector2f pos_canva =
        sfRectangleShape_getPosition(map_edit->buttons[1].rect[0]);
    pos_canva.x += move.x;
    pos_canva.y += move.y;
    sfRectangleShape_setPosition(map_edit->buttons[1].rect[0], pos_canva);
    for (u_int i = 0; i < map_edit->grid->limit.y; i++) {
        for (u_int j = 0; j < map_edit->grid->limit.x; j++) {
            map_edit->grid->tiles[i][j].position.x += move.x;
            map_edit->grid->tiles[i][j].position.y += move.y;
            move_tile(map_edit->grid->tiles[i][j]);
        }
    }
    move_col(map_edit, move);
    move_unit(map_edit, move);
    return;
}

void handle_view_event(map_edit_t *map_edit, bool *can_press)
{
    if (sfKeyboard_isKeyPressed(sfKeyS) && can_press) {
        move_view(map_edit, (sfVector2f){0, -TILE_SIZE});
        map_edit->delta_move.y -= TILE_SIZE;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD) && can_press) {
        move_view(map_edit, (sfVector2f){-TILE_SIZE, 0});
        map_edit->delta_move.x -= TILE_SIZE;
    }
    if (sfKeyboard_isKeyPressed(sfKeyZ) && can_press) {
        move_view(map_edit, (sfVector2f){0, TILE_SIZE});
        map_edit->delta_move.y += TILE_SIZE;
    }
    if (sfKeyboard_isKeyPressed(sfKeyQ) && can_press) {
        move_view(map_edit, (sfVector2f){TILE_SIZE, 0});
        map_edit->delta_move.x += TILE_SIZE;
    }
    return;
}
