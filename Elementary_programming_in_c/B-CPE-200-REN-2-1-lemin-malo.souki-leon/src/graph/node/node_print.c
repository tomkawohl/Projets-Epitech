/*
** EPITECH PROJECT, 2022
** src/graph/node
** File description:
** node_print
*/
/**
 * @file node_print.c
 *
 * @brief Has functions to print node of a graph structure
 *
 * @date 29/03/2023
*/
#include "src.h"

void node_print(node_element_t *node)
{
    if (node == NULL)
        return;
    z_printf("%d ", node->value);
    if (node->name != NULL) {
        z_printf("name->[%s] ", node->name);
    }
    z_printf("weight->[%d]\n", node->weight);
    return;
}
