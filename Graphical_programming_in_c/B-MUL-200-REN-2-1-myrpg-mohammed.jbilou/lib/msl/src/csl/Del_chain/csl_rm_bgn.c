/*
** EPITECH PROJECT, 2022
** rm_bgn
** File description:
** rm_bgn
*/

#include "msl.h"

void csl_rm_bgn(base_t **head)
{
    *head = (*head)->next;
    free((*head)->prev);
    (*head)->prev = NULL;
}
