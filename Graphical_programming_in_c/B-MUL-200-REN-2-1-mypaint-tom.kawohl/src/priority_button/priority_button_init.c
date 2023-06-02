/*
** EPITECH PROJECT, 2022
** priority_button
** File description:
** priority_button_init
*/
#include "my_paint.h"

priority_button_t *priority_button_init(void)
{
    priority_button_t *prio = malloc(sizeof(*prio));

    if (!prio)
        return (NULL);
    prio->size = 0;
    prio->first = NULL;
    prio->end = NULL;
    return (prio);
}
