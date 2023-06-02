/*
** EPITECH PROJECT, 2022
** src/graph
** File description:
** graph_destroy
*/
/**
 * @file graph_destroy.c
 *
 * @brief Has functions to destroy a graph struct
 *
 * @date 28/03/2023
*/
#include "src.h"

void adjacency_element_remove(adjacency_list_t list)
{
    node_element_t *node = NULL;
    node_element_t *tmp = NULL;

    if (list.start == NULL)
        return;
    node = list.start;
    while (node != NULL) {
        tmp = node;
        node = node->next;
        node_remove(tmp);
    }
}

void graph_destroy(graph_element_t *graph)
{
    u_int i = 0;

    if (graph == NULL)
        return;
    if (graph->neighbours != NULL) {
        for (; i < graph->nb_vertices; i++) {
            adjacency_element_remove(graph->neighbours[i]);
        }
        free(graph->neighbours);
    }
    if (graph->names != NULL)
        free_array_str2d(graph->names);
    free(graph);
}
