/*
** EPITECH PROJECT, 2022
** add_bgn
** File description:
** add_bgn
*/

#include "msl.h"

void csl_add_bgn(base_t **tail, void *data)
{
    base_t *element = malloc(sizeof(base_t));

    element->data = data;
    element->prev = NULL;
    (*tail)->prev = element;
    element->next = (*tail);
}
