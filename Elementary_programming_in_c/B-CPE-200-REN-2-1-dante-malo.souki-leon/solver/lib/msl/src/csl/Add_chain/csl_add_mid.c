/*
** EPITECH PROJECT, 2022
** add mid
** File description:
** add mid
*/

#include "msl.h"

void csl_add_mid(base_t *mid, void *data)
{
    base_t *chain = malloc(sizeof(base_t));

    chain->data = data;
    chain->next = mid->next;
    mid->next->prev = chain;
    mid->next = chain;
    chain->prev = mid;
}
