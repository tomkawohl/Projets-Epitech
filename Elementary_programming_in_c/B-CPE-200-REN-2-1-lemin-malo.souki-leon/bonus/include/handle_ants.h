/*
** EPITECH PROJECT, 2022
** include
** File description:
** handle_ants.h
*/
/**
 * @file handle_ants.h
 *
 * @brief Has functions that handle ants
 *
 * @date 04/04/2023
*/

#ifndef HANDLE_ANTS_H_
    #define HANDLE_ANTS_H_
    #include "graph.h"

/**
 * @brief Move an ant to a room, and print the message
 *
 * @param graph graph_element_t *graph
 * @param ant Index of the ant concerned
 * @param room Index of the room where the ant must go
 */
void ant_move(graph_element_t *graph, u_int ant, u_int room);

#endif /* HANDLE_ANTS_H_ */
