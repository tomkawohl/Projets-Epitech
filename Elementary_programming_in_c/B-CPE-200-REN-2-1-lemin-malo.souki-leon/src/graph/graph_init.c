/*
** EPITECH PROJECT, 2022
** src/graph
** File description:
** graph_init
*/
/**
 * @file graph_init.c
 *
 * @brief Has functions to init the graph with info
 *
 * @date 31/03/2023
*/
#include "src.h"

static void update_link(graph_element_t *graph, rooms_t room, u_int i)
{
    element_int_t *tmp = NULL;

    if (room.list == NULL)
        return;
    if (room.list->first == NULL)
        return;
    tmp = room.list->first;
    while (tmp) {
        edge_add(graph, i, tmp->value);
        tmp = tmp->next;
    }
    return;
}

static int *get_weight(graph_element_t *graph)
{
    int *tab = NULL;

    tab = malloc(sizeof(int) * graph->nb_vertices);
    if (check_malloc(tab, "graph_init.c"))
        return (NULL);
    for (u_int i = 0; i < graph->nb_vertices; i++)
        tab[i] = -1;
    return (tab);
}

static int init_ants_and_room(graph_element_t *graph, info_t *info)
{
    graph->nb_ants_start = info->nb_ants;
    graph->nb_ants_end = 0;
    graph->ants = malloc(sizeof(u_int) * info->nb_ants);
    if (check_malloc(graph->ants, "graph_init.c : allocation of graph->ants"))
        return (-1);
    graph->rooms = malloc(sizeof(bool) * graph->nb_vertices);
    if (check_malloc(graph->rooms, "graph_init.c : allocation of rooms"))
        return (-1);
    for (u_int i = 0; i < info->nb_ants; i++)
        graph->ants[i] = 0;
    for (u_int i = 0; i < graph->nb_vertices; i++)
        graph->rooms[i] = false;
    graph->ants_max = info->nb_ants;
    return (0);
}

static int init_weight(graph_element_t *graph, info_t *info)
{
    for (u_int i = 0; i < info->nb_cells; i++)
        update_link(graph, info->room[i], i);
    graph->weight = get_weight(graph);
    if (check_malloc(graph->weight, "graph_init.c")) {
        graph_destroy(graph);
        return (-1);
    }
    weight_set(graph);
    return (0);
}

graph_element_t *graph_init(info_t *info)
{
    graph_element_t *graph = NULL;
    if (info == NULL)
        return (NULL);
    graph = graph_create(info->nb_cells);
    if (check_malloc(graph, "graph_init.c")) {
        graph_destroy(graph);
        return (NULL);
    }
    if (init_ants_and_room(graph, info) == -1) {
        graph_destroy(graph);
        return (NULL);
    }
    graph->names = copy_array(info->cells);
    if (init_weight(graph, info) == -1)
        return (NULL);
    if (graph_has_solution(graph) == false) {
        graph_destroy(graph);
        return (NULL);
    }
    return (graph);
}
