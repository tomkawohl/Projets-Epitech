/*
** EPITECH PROJECT, 2023
** text_list
** File description:
** text_list_find
*/
/**
 * @file text_list_find.c
 *
 * @brief Find a text_t of a list of text
 *
 * @date 19/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "text_list.h"

text_t *text_list_find(text_list_t *list, char *name)
{
    text_t *text = NULL;

    if (list == NULL)
        return (NULL);
    if (list->first == NULL)
        return (NULL);
    text = list->first;
    while (text) {
        if (str_cmp(text->name, name) == 0)
            return (text);
        text = text->next;
    }
    return (NULL);
}
