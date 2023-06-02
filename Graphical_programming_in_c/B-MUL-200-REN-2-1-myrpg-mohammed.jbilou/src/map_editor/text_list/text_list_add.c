/*
** EPITECH PROJECT, 2023
** text_list
** File description:
** text_list_add
*/
/**
 * @file text_list_add.c
 *
 * @brief Add a text_t to a list of text
 *
 * @date 14/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "text_list.h"

static void set_text_pos(text_t *text, u_int size, char *str)
{
    sfFloatRect text_bound = sfText_getGlobalBounds(text->text);
    sfFloatRect text_bound_prev = sfText_getGlobalBounds(text->text);
    sfFloatRect sprite_bound = sfSprite_getGlobalBounds(text->sprite);
    sfVector2f pos = {0, 0};

    text_bound.width /= sprite_bound.width;
    text_bound.height /= sprite_bound.height;
    text_bound.width *= 1.2f;
    text_bound.height *= 1.2f;
    sfSprite_setScale(text->sprite, (sfVector2f){text_bound.width,
        text_bound.height});
    sprite_bound = sfSprite_getGlobalBounds(text->sprite);
    sfSprite_setPosition(text->sprite, text->text_pos);
    pos.x = fabs((text_bound_prev.width - sprite_bound.width) / 2);
    pos.y = fabs((text_bound_prev.height - sprite_bound.height) / 2);
    text->text_pos.x += pos.x;
    text->text_pos.y += pos.y;
    sfText_setPosition(text->text, text->text_pos);
}

static void set_to_add_pos(text_t *to_add, text_info_t info)
{
    float pos_x = (float)info.coord.x;

    pos_x += 0.09;
    if (info.type != T_INTERACT) {
        to_add->sprite_pos = (sfVector2f){info.coord.x * TILE_SIZE,
        info.coord.y * TILE_SIZE};
    } else {
        to_add->sprite_pos = (sfVector2f){pos_x * TILE_SIZE,
        info.coord.y * TILE_SIZE};
    }
    to_add->text_pos = to_add->sprite_pos;
}

static void set_value(text_t *to_add, text_info_t info)
{
    to_add->pos_tile = info.coord;
    to_add->asset = info.asset;
    to_add->tile_asset = NULL;
    if (info.tile_asset != NULL)
        to_add->tile_asset = str_cat(to_add->tile_asset,
            info.tile_asset);
    to_add->type = info.type;
    to_add->size = info.size;
}

static text_t *set_text(text_info_t info)
{
    text_t *to_add = malloc(sizeof(*to_add));
    if (!to_add)
        return (NULL);
    set_to_add_pos(to_add, info);
    to_add->name = NULL;
    if (info.name != NULL)
        to_add->name = str_cat(to_add->name, info.name);
    to_add->font = sfFont_createFromFile(TEXT_FONT);
    to_add->text = sfText_create();
    to_add->texture = sfTexture_createFromFile(info.tile_asset, &(info.asset));
    to_add->sprite = sfSprite_create();
    sfSprite_setTexture(to_add->sprite, to_add->texture, sfFalse);
    sfText_setFont(to_add->text, to_add->font);
    sfText_setCharacterSize(to_add->text, info.size);
    sfText_setFillColor(to_add->text, sfBlack);
    sfSprite_setPosition(to_add->sprite, to_add->sprite_pos);
    sfText_setString(to_add->text, info.text);
    set_text_pos(to_add, info.size, info.text);
    set_value(to_add, info);
    return (to_add);
}

void text_list_add(text_list_t *list, text_info_t info)
{
    text_t *to_add = NULL;

    if (!info.text)
        return;
    to_add = set_text(info);
    if (!verify_malloc(to_add, "text_list_add"))
        return;
    to_add->next = NULL;
    to_add->prev = NULL;
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
