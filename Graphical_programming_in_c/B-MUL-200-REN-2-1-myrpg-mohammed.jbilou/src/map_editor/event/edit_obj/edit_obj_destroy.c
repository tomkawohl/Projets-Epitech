/*
** EPITECH PROJECT, 2023
** map_editor
** File description:
** edit_obj_destroy
*/
/**
 * @file edit_obj_destroy.c
 *
 * @brief Destroy a list edit_obj
 *
 * @date 07/04/2023
*/
#include "src.h"
#include "lib_will.h"

void edit_obj_destroy(list_edit_obj_t *list)
{
    if (!list)
        return;
    while (list->first != NULL && list->size != 0)
        edit_obj_remove(list);
    free(list);
    return;
}
