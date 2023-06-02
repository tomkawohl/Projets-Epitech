/*
** EPITECH PROJECT, 2022
** src/graph
** File description:
** graph_print
*/
/**
 * @file graph_print.c
 *
 * @brief Has functions to print a graph structure
 *
 * @date 29/03/2023
*/
#include "src.h"

void graph_print(graph_element_t *graph)
{
    u_int i = 0;
    node_element_t *node = NULL;

    if (graph == NULL)
        return;
    for (; i < graph->nb_vertices; i++) {
        node = graph->neighbours[i].start;
        z_printf("Index %d : \n", i);
        if (graph->names[i] != NULL)
            z_printf("Name %s : \n", graph->names[i]);
        z_printf("Weight %d\n", graph->weight[i]);
        while (node != NULL) {
            node_print(node);
            node = node->next;
        }
        z_printf("\n");
    }
    return;
}
