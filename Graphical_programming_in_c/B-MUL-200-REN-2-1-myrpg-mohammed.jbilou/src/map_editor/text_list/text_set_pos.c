/*
** EPITECH PROJECT, 2023
** text_list
** File description:
** text_set_pos
*/
/**
 * @file text_set_pos.c
 *
 * @brief Set a position to a text of a text_list_t *
 *
 * @date 20/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "text_list.h"

void text_set_pos(text_list_t *list, char *name, sfVector2i pos)
{
    text_t *text = text_list_find(list, name);
    sfVector2f new_pos = {pos.x * TILE_SIZE, pos.y * TILE_SIZE};
    sfVector2f delta = {0, 0};

    if (text == NULL)
        return;
    delta.x = fabs(text->sprite_pos.x - text->text_pos.x);
    delta.y = fabs(text->sprite_pos.y - text->text_pos.y);
    text->sprite_pos = new_pos;
    text->text_pos = (sfVector2f){new_pos.x + delta.x, new_pos.y + delta.y};
    sfSprite_setPosition(text->sprite, text->sprite_pos);
    sfText_setPosition(text->text, text->text_pos);
}
