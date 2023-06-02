/*
** EPITECH PROJECT, 2022
** rm_chain
** File description:
** rm_chain
*/

#include "msl.h"

void csl_rm_chain(base_t *base)
{
    for (;base->next != NULL; base = base->next)
        free(base->prev);
    free(base);
}
