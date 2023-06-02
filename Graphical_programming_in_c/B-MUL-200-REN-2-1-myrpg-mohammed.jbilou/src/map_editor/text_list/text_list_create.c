/*
** EPITECH PROJECT, 2023
** text_list
** File description:
** text_list_create
*/
/**
 * @file text_list_create.c
 *
 * @brief Create a text list
 *
 * @date 14/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "text_list.h"

text_list_t *text_list_create(void)
{
    text_list_t *list = malloc(sizeof(*list));

    if (!verify_malloc(list, "text_list_create"))
        return (NULL);
    list->first = NULL;
    list->end = NULL;
    list->size = 0;
    return (list);
}
