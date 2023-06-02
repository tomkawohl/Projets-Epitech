/*
** EPITECH PROJECT, 2023
** map_editor
** File description:
** edit_obj_remove
*/
/**
 * @file edit_obj_remove.c
 *
 * @brief Remove a stack edit_obj
 *
 * @date 07/04/2023
*/
#include "src.h"
#include "lib_will.h"

void edit_obj_remove(list_edit_obj_t *list)
{
    edit_object_t *to_remove = NULL;

    if (!list)
        return;
    if (list->first == NULL)
        return;
    to_remove = list->first;
    list->first = list->first->next;
    sfTexture_destroy(to_remove->texture);
    sfSprite_destroy(to_remove->sprite);
    to_remove->next = NULL;
    free(to_remove);
    to_remove = NULL;
    list->size--;
    return;
}

static int remove_case_first(list_edit_obj_t *list, sfVector2i coord,
    edit_object_t *find)
{
    if (find->pos.x == coord.x && find->pos.y == coord.y) {
        list->first = find->next;
        sfTexture_destroy(find->texture);
        sfSprite_destroy(find->sprite);
        free(find);
        list->size--;
        return (true);
    }
    return (false);
}

static void remove_find(edit_object_t *find)
{
    sfTexture_destroy(find->texture);
    find->texture = NULL;
    sfSprite_destroy(find->sprite);
    find->sprite = NULL;
    free(find);
    find = NULL;
}

static bool is_list_correct(list_edit_obj_t *list)
{
    if (!list)
        return (false);
    if (list->first == NULL)
        return (false);
    return (true);
}

void edit_obj_remove_get(list_edit_obj_t *list, sfVector2i coord)
{
    edit_object_t *find = NULL;
    edit_object_t *prev = NULL;

    if (!is_list_correct(list))
        return;
    find = list->first;
    if (remove_case_first(list, coord, find))
        return;
    prev = find;
    while (find) {
        if (find->pos.x == coord.x && find->pos.y == coord.y) {
            prev->next = find->next;
            remove_find(find);
            return;
        }
        prev = find;
        find = find->next;
    }
    return;
}
