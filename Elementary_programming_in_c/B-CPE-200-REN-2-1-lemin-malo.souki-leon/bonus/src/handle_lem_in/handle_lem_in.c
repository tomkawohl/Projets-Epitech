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

void handle_lem_in(graph_element_t *graph, info_t *info)
{
    u_int limit = 0;

    z_printf("#moves\n");
    while (graph->nb_ants_end != graph->ants_max) {
        ants_move_all(graph, info);
        z_printf("\n");
        limit++;
        if (limit == 10000)
            return;
    }
}
