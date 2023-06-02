/*
** EPITECH PROJECT, 2022
** src/graph
** File description:
** graph_has_solution
*/
/**
 * @file graph_has_solution.c
 *
 * @brief Has functions that verify if start and end is connected
 *
 * @date 04/04/2023
*/
#include "src.h"


static void dfs(graph_element_t *graph, u_int node, bool *visited,
    bool *solution)
{
    node_element_t *neighbor = NULL;
    visited[node] = true;
    if (node == 0) {
        (*solution) = true;
        return;
    }
    if (graph->neighbours[node].start == NULL)
        return;
    neighbor = graph->neighbours[node].start;
    while (neighbor != NULL) {
        if (!visited[neighbor->value]) {
            dfs(graph, neighbor->value, visited, solution);
        }
        neighbor = neighbor->next;
    }
}

bool graph_has_solution(graph_element_t *graph)
{
    bool *visited = malloc(sizeof(bool) * graph->nb_vertices);
    bool solution = false;

    if (check_malloc(visited, "weight_set.c"))
        return (false);
    for (u_int i = 0; i < graph->nb_vertices; i++)
        visited[i] = false;
    dfs(graph, graph->nb_vertices - 1, visited, &solution);
    return (solution);
}
