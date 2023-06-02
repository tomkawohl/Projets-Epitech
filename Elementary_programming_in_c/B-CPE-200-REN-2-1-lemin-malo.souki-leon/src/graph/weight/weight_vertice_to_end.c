/*
** EPITECH PROJECT, 2022
** src/graph/weight
** File description:
** weight_vertice_to_end
*/
/**
 * @file weight_vertice_to_end.c
 *
 * @brief Has functions that can count how many vertices till the end
 *
 * @date 31/03/2023
*/
#include "src.h"

static int init_array(bool *marked, int *distance, list_int_t *list,
    u_int limit)
{
    if (marked == NULL || distance == NULL || list == NULL) {
        if (marked != NULL)
            free(marked);
        if (distance != NULL)
            free(distance);
        if (list != NULL)
            list_int_clear(list);
        print_error("weight_vertice_to_end.c : allocation failed\n");
        return (-1);
    }
    for (u_int i = 0 ; i < limit; i++) {
        marked[i] = false;
        distance[i] = -1;
    }
    return (0);
}

static void verify_node(graph_element_t *graph, list_int_t *list,
    weight_info_t *info, u_int node_idx)
{
    int idx_curr = list->first->value;
    int neighbor_idx = 0;
    node_element_t *node_curr = graph->neighbours[idx_curr].start;

    list_int_remove_end(list);
    while (node_curr != NULL) {
        neighbor_idx = node_curr->value;
        if (info->marked[neighbor_idx] == false
            && neighbor_idx >= (int)node_idx) {
            info->marked[neighbor_idx] = true;
            info->distance[neighbor_idx] = info->distance[idx_curr] + 1;
            list_int_add(list, neighbor_idx);
        }
        node_curr = node_curr->next;
    }
}

static weight_info_t *init_weight_info(graph_element_t *graph, list_int_t *list)
{
    weight_info_t *info = malloc(sizeof(*info));

    if (info == NULL) {
        print_error("weight_vertice_to_end.c : allocation failed\n");
        return (NULL);
    }
    info->marked = malloc(sizeof(bool) * (graph->nb_vertices));
    info->distance = malloc(sizeof(int) * (graph->nb_vertices));
    if (init_array(info->marked, info->distance,
        list, graph->nb_vertices) == -1) {
        free(info);
        return (NULL);
    }
    return (info);

}

u_int weight_vertice_to_end(graph_element_t *graph, u_int node_idx)
{
    if (node_idx >= graph->nb_vertices)
        return (0);
    list_int_t *list = list_int_create();
    u_int nb_vertice = 0;
    weight_info_t *info = init_weight_info(graph, list);

    if (info == NULL)
        return (0);
    list_int_add(list, node_idx);
    info->marked[node_idx] = true;
    while (list->first != NULL) {
        verify_node(graph, list, info, node_idx);
    }
    nb_vertice = info->distance[graph->nb_vertices - 1];
    free(info->marked);
    free(info->distance);
    free(info);
    list_int_clear(list);
    return (nb_vertice);
}
