/*
** EPITECH PROJECT, 2022
** handle_ants
** File description:
** ant_move
*/
/**
 * @file ant_move.c
 *
 * @brief Has functions to move ants on the graph
 *
 * @date 04/04/2023
*/
#include "src.h"

void ant_move(graph_element_t *graph, u_int ant, u_int room)
{
    if (ant > (graph->ants_max - 1))
        return;
    if (room > graph->nb_vertices - 1)
        return;
    graph->rooms[graph->ants[ant]] = false;
    graph->ants[ant] = room;
    graph->rooms[room] = true;
    z_printf("P%d-%s", ant + 1, graph->names[room]);
    return;
}
