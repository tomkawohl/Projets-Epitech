/*
** EPITECH PROJECT, 2023
** map_editor
** File description:
** edit_obj_draw
*/
/**
 * @file edit_obj_draw.c
 *
 * @brief Draw all element of list of edit_obj
 *
 * @date 07/04/2023
*/
#include "src.h"
#include "lib_will.h"

void edit_obj_draw(sfRenderWindow *win, list_edit_obj_t *list)
{
    edit_object_t *tmp = NULL;

    if (!list)
        return;
    if (!list->first)
        return;
    tmp = list->first;
    while (tmp) {
        sfRenderWindow_drawSprite(win, tmp->sprite, NULL);
        tmp = tmp->next;
    }
    return;
}
