/*
** EPITECH PROJECT, 2023
** text_list
** File description:
** text_list_change
*/
/**
 * @file text_list_change.c
 *
 * @brief Change a text_t to a list of text
 *
 * @date 18/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "text_list.h"
#include "game_actor.h"

struct game_s;


void text_list_change(struct game_s *gm, char *text, char *name)
{
    text_t *find = text_list_find(gm->list_text, name);
    text_t *prev;
    text_t *next;

    if (find == NULL)
        return;
    text_list_add(gm->list_text, (text_info_t){find->name, find->pos_tile,
    text, find->size, find->tile_asset, find->asset, find->type});
    prev = find->prev;
    next = find->next;
    if (next != NULL)
        next->prev = prev;
    if (prev != NULL)
        prev->next = next;
    text_t_destroy(find);
    return;
}
