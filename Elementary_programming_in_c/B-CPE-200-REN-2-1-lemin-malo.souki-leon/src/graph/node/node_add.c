/*
** EPITECH PROJECT, 2022
** src/graph/node
** File description:
** node_add
*/
/**
 * @file node_add.c
 *
 * @brief Has functions to add node to a graph structure
 *
 * @date 28/03/2023
*/
#include "src.h"

static int is_node_allocated(node_element_t *node)
{
    if (node == NULL) {
        print_error("Node_add.c : node allocation failed\n");
        return (false);
    }
    return (true);
}

node_element_t *node_add(unsigned int value)
{
    node_element_t *node = malloc(sizeof(*node));

    if (is_node_allocated(node) == false)
        return (NULL);
    node->name = NULL;
    node->value = value;
    node->weight = -1;
    node->next = NULL;
    return (node);
}
