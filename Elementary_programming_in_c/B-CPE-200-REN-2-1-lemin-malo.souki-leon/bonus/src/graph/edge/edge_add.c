/*
** EPITECH PROJECT, 2022
** src/graph/edge
** File description:
** edge_add
*/
/**
 * @file edge_add.c
 *
 * @brief Has functions to add an edge to a graph struct
 *
 * @date 29/03/2023
*/
#include "src.h"

static bool is_already_linked(graph_element_t *graph, u_int src, u_int dest)
{
    node_element_t *node = NULL;

    if (graph->neighbours[src].start == NULL)
        return (false);
    node = graph->neighbours[src].start;
    while (node) {
        if (dest == node->value)
            return (true);
        node = node->next;
    }
    return (false);
}

void edge_add(graph_element_t *graph, u_int src, u_int dest)
{
    node_element_t *node = NULL;

    if (src > (graph->nb_vertices - 1) || dest > (graph->nb_vertices - 1))
        return;
    if (is_already_linked(graph, src, dest))
        return;
    node = node_add(dest);
    if (node == NULL)
        return;
    node_add_name(node, graph->names[dest]);
    node->next = graph->neighbours[src].start;
    graph->neighbours[src].start = node;
    node = node_add(src);
    if (node == NULL)
        return;
    node_add_name(node, graph->names[src]);
    node->next = graph->neighbours[dest].start;
    graph->neighbours[dest].start = node;
}

/*
donner l'index du char ** qui contiendra le name à donner au node
*/
