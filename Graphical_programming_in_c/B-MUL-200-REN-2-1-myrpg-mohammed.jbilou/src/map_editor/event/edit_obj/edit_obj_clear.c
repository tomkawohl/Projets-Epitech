/*
** EPITECH PROJECT, 2023
** map_editor
** File description:
** edit_obj_clear
*/
/**
 * @file edit_obj_clear.c
 *
 * @brief Clear a list of edit_obj
 *
 * @date 07/04/2023
*/
#include "src.h"
#include "lib_will.h"

void edit_obj_clear(list_edit_obj_t *list)
{
    if (!list)
        return;
    if (list->first == NULL)
        return;
    while (list->first) {
        edit_obj_remove(list);
    }
    return;
}
