/*
** EPITECH PROJECT, 2022
** link
** File description:
** link_add
*/
#include "../../include/tools.h"
#include <unistd.h>
#include <stdlib.h>

void add_link_end(link_t **link, int data)
{
    link_t *tp;
    link_t *new_node = malloc(sizeof(link_t));

    new_node->prev = NULL;
    new_node->data = data;
    new_node->next = NULL;
    tp = *link;
    for (; tp->next != NULL; tp = tp->next);
    tp->next = new_node;
    new_node->prev = tp;
}
