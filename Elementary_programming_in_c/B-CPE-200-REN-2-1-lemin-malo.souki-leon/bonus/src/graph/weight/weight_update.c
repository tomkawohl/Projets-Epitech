/*
** EPITECH PROJECT, 2022
** src/graph/weight
** File description:
** weight_update
*/
/**
 * @file weight_update.c
 *
 * @brief Has functions to update weight of node of a graph
 *
 * @date 31/03/2023
*/
#include "src.h"

static int init_int_array(int *visited, int *distance, int *predecessor,
    u_int limit)
{
    if (visited == NULL || distance == NULL || predecessor == NULL) {
        if (visited != NULL)
            free(visited);
        if (distance != NULL)
            free(distance);
        if (predecessor != NULL)
            free(predecessor);
        print_error("weight_update.c : allocation of int array failed\n");
        return (-1);
    }
    for (u_int i = 0; i < limit; i++) {
        visited[i] = false;
        distance[i] = INT_MAX;
        predecessor[i] = -1;
    }
    distance[0] = 0;
    return (0);
}

static void free_int_array(int *visited, int *distance, int *predecessor)
{
    free(visited);
    free(distance);
    free(predecessor);
}

static void check_neighbours(graph_element_t *graph, int *distance,
    int *predecessor, neighbor_info_t info)
{
    node_element_t *node = graph->neighbours[info.next].start;

    while (node != NULL) {
        if (node->value == info.j
            && distance[info.next] + 1 < distance[info.j]) {
            distance[info.j] = distance[info.next] + 1;
            predecessor[info.j] = info.next;
        }
        node = node->next;
    }
}

static void calcul_distance(graph_element_t *graph, int *visited,
    int *distance, int *predecessor)
{
    int min_dist = INT_MAX;
    u_int next = 0;

    for (u_int j = 0; j < graph->nb_vertices; j++) {
        if (visited[j] == false && distance[j] < min_dist) {
            min_dist = distance[j];
            next = j;
        }
    }
    visited[next] = true;
    for (u_int j = 0; j < graph->nb_vertices; j++) {
        if (visited[j] == false && graph->neighbours[next].start != NULL) {
            check_neighbours(graph, distance,
                predecessor, (neighbor_info_t){next, j});
        }
    }
}

void weight_update(graph_element_t *graph)
{
    int *visited = malloc(sizeof(int) * graph->nb_vertices);
    int *distance = malloc(sizeof(int) * graph->nb_vertices);
    int *predecessor = malloc(sizeof(int) *graph->nb_vertices);

    if (init_int_array(visited, distance, predecessor, graph->nb_vertices)
        == -1)
        return;
    for (u_int i = 0; i < graph->nb_vertices; i++) {
        calcul_distance(graph, visited, distance, predecessor);
    }
    weight_add(graph, distance, predecessor);
    free_int_array(visited, distance, predecessor);
    return;
}
