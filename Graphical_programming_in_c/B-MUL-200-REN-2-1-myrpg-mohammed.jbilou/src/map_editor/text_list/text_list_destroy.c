/*
** EPITECH PROJECT, 2023
** text_list
** File description:
** text_list_destroy
*/
/**
 * @file text_list_destroy.c
 *
 * @brief Destroy a text_t_list *
 *
 * @date 14/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "text_list.h"

void text_list_destroy(text_list_t *list)
{
    if (!list)
        return;
    while (list->first) {
        text_list_remove(list);
    }
    free(list);
    list = NULL;
}
