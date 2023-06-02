/*
** EPITECH PROJECT, 2022
** include
** File description:
** handle_lem_in.h
*/
/**
 * @file handle_lem_in.h
 *
 * @brief Has functions that handle lem_in procedure
 *
 * @date 04/04/2023
*/

#ifndef HANDLE_LEM_IN_H_
    #define HANDLE_LEM_IN_H_
    #include "graph.h"

/**
 * @brief Handle all the lem_in program
 *
 * @param graph graph_element_t *
 *
 */
void handle_lem_in(graph_element_t *graph, info_t *info);

/**
 * @brief Find the minimal way to the end
 *
 * @param graph graph_element_t *
 * @param index Index where it has to search the way
 * @return u_int The index of the room where it has to go
 */
u_int find_way(graph_element_t *graph, u_int index);

/**
 * @brief Move every ant if they can
 *
 * @param graph graph_element_t *
 */
void ants_move_all(graph_element_t *graph, info_t *info);

/**
 * @brief final display
 *
 * @param file
 * @param type
 */
void file_parser_display(char **file, bool type);

#endif /* HANDLE_LEM_IN */
