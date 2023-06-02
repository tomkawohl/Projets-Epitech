/*
** EPITECH PROJECT, 2022
** handle_lem_in
** File description:
** handle_lem_in
*/
/**
 * @file handle_lem_in.c
 *
 * @brief Has functions that handle all the procedure of lem_in program
 *
 * @date 04/04/2023
*/
#include "src.h"

/*
void handle_lem_in(graph_element_t *graph)
{
    u_int limit = 0;
    u_int ant_moved = 1;
    node_element_t *node = graph->neighbours[0].start;
    u_int way = 0;
    int weight = -1;

    while (node) {
        if (graph->weight[node->value] < weight || weight == -1) {
            way = node->value;
            weight = graph->weight[node->value];
        }
        node = node->next;
    }
    ant_move(graph, 0, way);
    while (graph->nb_ants_end != graph->ants_max) {
        limit++;
        if (limit == 10000)
            return;
    }
}
*/

u_int find_new_way(graph_element_t *graph, u_int index, u_int way)
{
    u_int new_way = way;
    node_element_t *node = graph->neighbours[index].start;
    int weight = INT_MAX;

    weight = graph->weight[node->value];
    while (node) {
        if (graph->weight[node->value] < weight
        && graph->weight[node->value] != -1
        && graph->weight[node->value] != (int)way
        && graph->weight[node->value] < (int)graph->nb_ants_start) {
            new_way = node->value;
            weight = graph->weight[node->value];
        }
        node = node->next;
    }
    return (new_way);
}

u_int find_way(graph_element_t *graph, u_int index)
{
    node_element_t *node = graph->neighbours[index].start;
    u_int way = 0;
    int weight = INT_MAX;

    while (node) {
        if (graph->weight[node->value] < weight
            && graph->weight[node->value] != -1) {
            way = node->value;
            weight = graph->weight[node->value];
        }
        node = node->next;
    }
    return (way);
}

void handle_lem_in(graph_element_t *graph)
{
    u_int limit = 0;

    z_printf("#moves\n");
    while (graph->nb_ants_end != graph->ants_max) {
        ants_move_all(graph);
        z_printf("\n");
        limit++;
        if (limit == 10000)
            return;
    }
}
