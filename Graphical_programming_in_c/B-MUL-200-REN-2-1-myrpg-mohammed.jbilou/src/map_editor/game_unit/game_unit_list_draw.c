/*
** EPITECH PROJECT, 2023
** game_unit
** File description:
** game_unit_list_draw
*/
/**
 * @file game_unit_list_draw.c
 *
 * @brief Draw all game unit of game_unit_list_t *
 *
 * @date 16/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "game_unit.h"

void game_unit_list_draw(sfRenderWindow *win, game_unit_list_t *list)
{
    game_unit_t *unit = NULL;

    if (!list)
        return;
    if (!list->first)
        return;
    unit = list->first;
    while (unit) {
        if (unit->sprite)
            sfRenderWindow_drawSprite(win, unit->sprite, NULL);
        unit = unit->next;
    }
    return;
}
