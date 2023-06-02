/*
** EPITECH PROJECT, 2023
** game_unit
** File description:
** game_unit_list_add
*/
/**
 * @file game_unit_list_add.c
 *
 * @brief Add a game unit to a list
 *
 * @date 16/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "game_unit.h"

static void set_value(game_unit_t *to_add, game_unit_info_t info)
{
    to_add->pos_grid = info.pos_grid;
    to_add->pos_asset = info.pos_asset;
    to_add->set = info.set;
    to_add->next = NULL;
    to_add->prev = NULL;
}

static game_unit_t *set_game_unit(game_unit_info_t info)
{
    game_unit_t *to_add = malloc(sizeof(*to_add));
    sfVector2f pos = (sfVector2f){info.pos_grid.x * TILE_SIZE,
        info.pos_grid.y * TILE_SIZE};
    SET_ALL;
    sfIntRect area = {info.pos_asset.x * TILE_SIZE, info.pos_asset.y *
        TILE_SIZE, TILE_SIZE, TILE_SIZE};

    if (!verify_malloc(to_add, "set game unit"))
        return (NULL);
    to_add->pos = pos;
    to_add->pos_grid = info.pos_grid;
    to_add->texture = sfTexture_createFromFile(set[info.set], &(area));
    to_add->sprite = sfSprite_create();
    if (to_add->texture == NULL || to_add->sprite == NULL)
        return (NULL);
    sfSprite_setTexture(to_add->sprite, to_add->texture, sfFalse);
    sfSprite_setPosition(to_add->sprite, to_add->pos);
    set_value(to_add, info);
    return (to_add);
}

void game_unit_list_add(game_unit_list_t *list, game_unit_info_t info)
{
    game_unit_t *to_add = NULL;

    if (!list)
        return;
    to_add = set_game_unit(info);
    if (!to_add)
        return;
    if (list->first == NULL) {
        list->first = to_add;
        list->end = to_add;
        list->size++;
        return;
    }
    list->first->prev = to_add;
    to_add->next = list->first;
    list->first = to_add;
    list->size++;
    return;
}
