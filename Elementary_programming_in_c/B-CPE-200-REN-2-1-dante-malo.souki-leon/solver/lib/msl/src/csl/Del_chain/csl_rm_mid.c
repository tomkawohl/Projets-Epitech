/*
** EPITECH PROJECT, 2022
** rm_bgn
** File description:
** rm_bgn
*/

#include "msl.h"

void csl_rm_mid(base_t *head)
{
    head->prev->next = head->next;
    head->next->prev = head->prev;
    free(head);
}
