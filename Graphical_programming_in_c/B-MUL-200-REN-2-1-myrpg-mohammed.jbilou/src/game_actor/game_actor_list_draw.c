/*
** EPITECH PROJECT, 2023
** game_actor
** File description:
** game_actor_draw
*/
/**
 * @file game_actor_draw.c
 *
 * @brief Draw a game actor list
 *
 * @date 12/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "game_actor.h"

void game_actor_list_draw(sfRenderWindow *win, game_actor_list_t *list)
{
    game_actor_t *game_actor = NULL;

    if (!list)
        return;
    if (!list->first)
        return;
    game_actor = list->first;
    while (game_actor) {
        if (game_actor->sprite != NULL)
            sfRenderWindow_drawSprite(win, game_actor->sprite, NULL);
        game_actor = game_actor->next;
    }
    return;
}
