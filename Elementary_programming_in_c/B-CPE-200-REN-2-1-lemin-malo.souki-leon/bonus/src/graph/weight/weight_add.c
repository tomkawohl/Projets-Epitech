/*
** EPITECH PROJECT, 2022
** src/graph/weight
** File description:
** weight_add
*/
/**
 * @file weight_add.c
 *
 * @brief Has functions that all weight for graph
 *
 * @date 31/03/2023
*/
#include "src.h"

void weight_add_node(graph_element_t *graph, int *distance, int *predecessor,
    u_int i)
{
    node_element_t *node = graph->neighbours[i].start;

    while (node != NULL) {
        if (node->value == (u_int)predecessor[i]) {
            node->weight = distance[i] - distance[predecessor[i]];
            break;
        }
        node = node->next;
    }
}

void weight_add(graph_element_t *graph, int *distance, int *predecessor)
{
    for (u_int i = 0; i < graph->nb_vertices; i++) {
        if (predecessor[i] != -1) {
            weight_add_node(graph, distance, predecessor, i);
        }
    }
    return;
}
