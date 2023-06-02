/*
** EPITECH PROJECT, 2022
** new_chaine
** File description:
** new_chaine
*/

#include "msl.h"

void csl_add_end(base_t *tail, void *data)
{
    base_t *element = malloc(sizeof(base_t));

    element->data = data;
    element->next = NULL;
    for (;tail->next != NULL; tail = tail->next);
    tail->next = element;
    element->prev = tail;
}
