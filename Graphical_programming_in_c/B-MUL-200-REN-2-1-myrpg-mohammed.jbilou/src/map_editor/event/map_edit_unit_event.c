/*
** EPITECH PROJECT, 2023
** map_editor
** File description:
** event/map_edit_unit.c
*/
/**
 * @file map_edit_unit.c
 *
 * @brief Add data of map_edit_unit
 *
 * @date 16/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include <math.h>

static void delete_game_unit(map_edit_t *map_edit, game_unit_t *unit)
{
    game_unit_t *tmp = NULL;
    game_unit_t *prev = NULL;
    game_unit_t *next = NULL;

    if (map_edit->units->first == unit) {
        game_unit_list_remove(map_edit->units);
        return;
    }
    prev = unit->prev;
    next = unit->next;
    if (next != NULL)
        next->prev = prev;
    if (prev != NULL)
        prev->next = next;
    game_unit_remove(unit);
    return;
}

static void delete_unit(map_edit_t *map_edit, sfVector2i coord)
{
    game_unit_t *unit = NULL;
    game_unit_t *tmp = NULL;

    if (map_edit->units == NULL)
        return;
    if (map_edit->units->first == NULL)
        return;
    unit = map_edit->units->first;
    while (unit) {
        if (unit->pos_grid.x == coord.x && unit->pos_grid.y == coord.y) {
            delete_game_unit(map_edit, unit);
            return;
        }
        unit = unit->next;
    }
    return;
}

void map_edit_unit_delete_event(map_edit_t *map_edit,
    sfMouseButtonEvent *mouse)
{
    sfFloatRect bound = {0};
    sfVector2i index = {0, 0};
    sfVector2f pos = {0, 0};

    if (map_edit->state != UNIT_DELETE)
        return;
    bound = sfRectangleShape_getGlobalBounds(map_edit->buttons[1].rect[0]);
    if (!sfFloatRect_contains(&bound, (float)mouse->x, (float)mouse->y))
        return;
    pos = sfRectangleShape_getPosition(map_edit->buttons[1].rect[0]);
    if (mouse->x - pos.x != 0)
        index.x = (int)((mouse->x - pos .x) / TILE_SIZE);
    if (mouse->y - pos.y != 0)
        index.y = (int)((mouse->y - pos.y) / TILE_SIZE);
    delete_unit(map_edit, index);
    return;
}

static void update_pos(map_edit_t *map_edit)
{
    sfVector2f pos = map_edit->units->first->pos;

    pos.x += CANVA_X + map_edit->delta_move.x;
    pos.y += CANVA_Y + map_edit->delta_move.y;
    sfSprite_setPosition(map_edit->units->first->sprite, pos);
    map_edit->units->first->pos = pos;
    return;
}

void map_edit_unit_event(map_edit_t *map_edit, sfMouseButtonEvent *mouse)
{
    sfFloatRect bound = {0};
    sfVector2i index = {0, 0};
    sfVector2f pos = {0, 0};

    if (map_edit->state != UNIT)
        return;
    bound = sfRectangleShape_getGlobalBounds(map_edit->buttons[1].rect[0]);
    if (!sfFloatRect_contains(&bound, (float)mouse->x, (float)mouse->y))
        return;
    pos = sfRectangleShape_getPosition(map_edit->buttons[1].rect[0]);
    if (mouse->x - pos.x != 0)
        index.x = (int)((mouse->x - pos .x) / TILE_SIZE);
    if (mouse->y - pos.y != 0)
        index.y = (int)((mouse->y - pos.y) / TILE_SIZE);
    game_unit_list_add(map_edit->units,(game_unit_info_t){(sfVector2i){
        index.x, index.y}, map_edit->tile_coord_select, map_edit->set_nb});
    update_pos(map_edit);
    return;
}
