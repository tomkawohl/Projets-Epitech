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
/*
char *ant_move(graph_element_t *graph, u_int ant, u_int room)
{
    char *str_move = NULL;
    char *str_ant = NULL;
    char *str_room = NULL;

    if (ant > (graph->ants_max - 1))
        return (NULL);
    if (room > graph->nb_vertices - 1)
        return (NULL);
    graph->ants[ant] = room;
    graph->rooms[room] = true;
    str_ant = int_to_string(ant);
    str_room = int_to_string(room);
    str_move = str_recat(str_move, "P");
    str_move = str_recat(str_move, ant);
    str_move = str_recat(str_move, "-");
    str_move = str_recat(str_move, str_room);
//    z_printf("P%d-%s ", ant + 1, graph->names[room]);
    return (str_move);
}
*/

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
