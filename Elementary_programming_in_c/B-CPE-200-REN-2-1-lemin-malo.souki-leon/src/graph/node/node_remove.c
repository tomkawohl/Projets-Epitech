/*
** EPITECH PROJECT, 2022
** src/graph/node
** File description:
** node_remove
*/
/**
 * @file node_remove.c
 *
 * @brief Has functions to remove a node of a graph
 *
 * @date 28/03/2023
*/
#include "src.h"

void node_remove(node_element_t *node)
{
    if (node == NULL)
        return;
    if (node->name != NULL)
        free(node->name);
    free(node);
}
