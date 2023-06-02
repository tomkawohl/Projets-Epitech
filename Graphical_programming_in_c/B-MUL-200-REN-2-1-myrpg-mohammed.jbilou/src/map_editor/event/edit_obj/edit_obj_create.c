/*
** EPITECH PROJECT, 2023
** map_editor
** File description:
** edit_obj_create
*/
/**
 * @file edit_obj_create.c
 *
 * @brief Create a stack edit_obj
 *
 * @date 07/04/2023
*/
#include "src.h"
#include "lib_will.h"

list_edit_obj_t *edit_obj_create(void)
{
    list_edit_obj_t *list = malloc(sizeof(*list));

    if (!verify_malloc(list, "edit_obj_create"))
        return (NULL);
    list->first = NULL;
    list->size = 0;
    return (list);
}
