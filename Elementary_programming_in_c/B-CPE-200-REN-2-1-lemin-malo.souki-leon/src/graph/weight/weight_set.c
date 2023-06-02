/*
** EPITECH PROJECT, 2022
** src/graph/weight
** File description:
** weight_set
*/
/**
 * @file weight_set.c
 *
 * @brief Has functions that set all weight of a graph
 *
 * @date 04/04/2023
*/
#include "src.h"

static void dfs(graph_element_t *graph, u_int node, bool *visited,
    int *distance)
{
    node_element_t *neighbor = NULL;
    visited[node] = true;
    if (node == 0) {
        (*distance) = 1;
        return;
    }
    if (graph->neighbours[node].start == NULL) return;
    if ((*distance) < graph->weight[node] || graph->weight[node] == -1) {
        graph->weight[node] = (*distance);
        graph->neighbours[node].start->weight = (*distance);
    }
    if (graph->neighbours[node].start->next == NULL) return;
    neighbor = graph->neighbours[node].start->next;
    while (neighbor != NULL) {
        if (!visited[neighbor->value]) {
            (*distance)++;
            dfs(graph, neighbor->value, visited, distance);
        }
        neighbor = neighbor->next;
    }
}

void weight_set(graph_element_t *graph)
{
    bool *visited = malloc(sizeof(bool) * graph->nb_vertices);
    int distance = 0;

    if (check_malloc(visited, "weight_set.c"))
        return;
    for (u_int i = 0; i < graph->nb_vertices; i++)
        visited[i] = false;
    for (u_int i = (graph->nb_vertices - 1); i != 0 ; i--) {
        dfs(graph, i, visited, &distance);
    }
    return;
}
