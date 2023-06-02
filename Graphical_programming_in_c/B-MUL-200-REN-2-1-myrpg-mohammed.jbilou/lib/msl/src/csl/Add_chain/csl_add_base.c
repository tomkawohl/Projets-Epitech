/*
** EPITECH PROJECT, 2022
** bas
** File description:
** base
*/

#include "msl.h"

base_t *csl_add_base(base_t *start, void *data)
{
    start = malloc(sizeof(base_t));
    start->data = data;
    start->next = NULL;
    start->prev = NULL;
    return start;
}
