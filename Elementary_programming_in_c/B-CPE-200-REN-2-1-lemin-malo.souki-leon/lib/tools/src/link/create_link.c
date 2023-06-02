/*
** EPITECH PROJECT, 2022
** link
** File description:
** create_link
*/
#include "../../include/tools.h"
#include <unistd.h>
#include <stdlib.h>

link_t *create_list(link_t *node, void *data)
{
    link_t *new_node = malloc(sizeof(link_t));

    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    node = new_node;

    return node;
}
