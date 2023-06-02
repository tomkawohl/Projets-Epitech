/*
** EPITECH PROJECT, 2023
** text_list
** File description:
** text_list_update
*/
/**
 * @file text_list_update.c
 *
 * @brief Update a text_t to a list of text
 *
 * @date 19/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "text_list.h"

void update_quest_pos(struct game_s *gm)
{
    text_t *quest = text_list_find(gm->list_text, "quest");
    sfVector2f text_pos = {0, 0};
    sfVector2f sprite_pos = {0, 0};

    if (quest == NULL)
        return;
    sprite_pos = quest->sprite_pos;
    sprite_pos.x += gm->delta_move.x;
    sprite_pos.y += gm->delta_move.y;
    text_pos = quest->text_pos;
    text_pos.x += gm->delta_move.x;
    text_pos.y += gm->delta_move.y;
    sfSprite_setPosition(quest->sprite, sprite_pos);
    sfText_setPosition(quest->text, text_pos);
}
