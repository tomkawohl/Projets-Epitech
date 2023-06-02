/*
** EPITECH PROJECT, 2022
** rm_bgn
** File description:
** rm_bgn
*/

#include "msl.h"

void csl_rm_end(base_t *tail)
{
    for (; tail->next != NULL; tail = tail->next);
    tail = tail->prev;
    free(tail->next);
    tail->next = NULL;
}
