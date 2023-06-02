/*
** EPITECH PROJECT, 2022
** show_chain
** File description:
** show_chain
*/

#include "msl.h"

void psl_show_chain(base_t *chain)
{
    for (;chain->prev != NULL; chain = chain->prev);
    for (;chain; chain = chain->next)
        psl_printf("->%d", chain->data);
    psl_printf("\n");
}
