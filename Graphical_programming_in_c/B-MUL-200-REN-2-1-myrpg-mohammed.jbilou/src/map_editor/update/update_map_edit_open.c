/*
** EPITECH PROJECT, 2023
** map_editor
** File description:
** update_map_edit_open
*/
/**
 * @file update_map_edit_open.c
 *
 * @brief Update map_edit when open a new map
 *
 * @date 10/04/2023
*/
#include "src.h"
#include "lib_will.h"

static void update_unit(map_edit_t *map_edit)
{
    game_unit_t *tmp = NULL;

    if (map_edit->units == NULL)
        return;
    if (map_edit->units->first == NULL)
        return;
    tmp = map_edit->units->first;
    while (tmp) {
        tmp->pos.x += CANVA_X;
        tmp->pos.y += CANVA_Y;
        tmp->pos.x += map_edit->delta_move.x;
        tmp->pos.y += map_edit->delta_move.y;
        sfSprite_setPosition(tmp->sprite, tmp->pos);
        tmp = tmp->next;
    }
}

void update_map_edit_open(map_edit_t *map_edit, char *input)
{
    update_colision(map_edit);
    update_unit(map_edit);
    map_edit->state = DEFAULT;
    free(input);
}
