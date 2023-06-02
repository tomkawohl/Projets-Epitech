/*
** EPITECH PROJECT, 2023
** map_editor
** File description:
** edit_obj_add
*/
/**
 * @file edit_obj_add.c
 *
 * @brief Add an element edit_obj
 *
 * @date 07/04/2023
*/
#include "src.h"
#include "lib_will.h"

static edit_object_t *set_edit_obj(sfVector2i coord, sfIntRect area,
    map_edit_t *map_edit)
{
    edit_object_t *to_add = malloc(sizeof(*to_add));
    sfVector2f pos = {0, 0};

    if (!verify_malloc(to_add,"edit_obj_add"))
        return (NULL);
    to_add->texture = sfTexture_createFromFile(CURSOR_ASSET, &area);
    to_add->sprite = sfSprite_create();
    sfSprite_setTexture(to_add->sprite, to_add->texture, sfFalse);
    pos.x = coord.x * TILE_SIZE + CANVA_X + map_edit->delta_move.x;
    pos.y = coord.y * TILE_SIZE + CANVA_Y + map_edit->delta_move.y;
    sfSprite_setScale(to_add->sprite, (sfVector2f){3.0, 3.0});
    sfSprite_setPosition(to_add->sprite, pos);
    to_add->pos = coord;
}

void edit_obj_add(list_edit_obj_t *list, sfVector2i coord, sfIntRect area,
    map_edit_t *map_edit)
{
    edit_object_t *to_add = set_edit_obj(coord, area, map_edit);

    if (!verify_malloc(to_add,"edit_obj_add"))
        return;
    list->size++;
    to_add->next = NULL;
    if (list->first == NULL)
        list->first = to_add;
    else {
        to_add->next = list->first;
        list->first = to_add;
    }
    return;
}
