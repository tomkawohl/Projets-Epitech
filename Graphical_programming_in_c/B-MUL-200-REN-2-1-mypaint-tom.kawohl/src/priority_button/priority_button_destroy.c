/*
** EPITECH PROJECT, 2022
** priority_button
** File description:
** priority_button_destroy
*/
#include "my_paint.h"

void priority_button_destroy(priority_button_t *prio)
{
    if (!prio)
        return;
    while (prio->first != NULL && prio->size != 0){
        priority_button_remove(prio);
    }
    free(prio);
}
