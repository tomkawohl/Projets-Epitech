/*
** EPITECH PROJECT, 2022
** src/graph/node
** File description:
** node_add_name
*/
/**
 * @file node_add_name.c
 *
 * @brief Has functions to add a name to a node of a graph structure
 *
 * @date 29/03/2023
*/
#include "src.h"

void node_add_name(node_element_t *node, char *name)
{
    if (node == NULL || name == NULL)
        return;
    node->name = NULL;
    node->name = str_cat(node->name, name);
    return;
}
