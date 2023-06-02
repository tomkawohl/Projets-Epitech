/*
** EPITECH PROJECT, 2022
** parser
** File description:
** parser
*/

#ifndef ERRORS
    #define ERRORS

    #include <stdlib.h>
    #include <stdbool.h>
    #include "parser.h"
    #define UNUSED __attribute__((unused))
    #define NB_COLS 3

/**
 * @brief check if a malloc has failed and returns false if it's the case
 * @brief the function will print where the malloc failed
 * @param alloc
 * @param filename
 * @return int
 */
int check_malloc(void *alloc, char const *filename);

/**
 * @brief check if the file has start and end
 *
 * @param info
 * @return true
 * @return false
 */
bool check_file(info_t *info);


/**
 * @brief destroy all the elements in the program
 *
 * @param info
 * @param graph_element_t graph_element_t *
 */
void destroy_program(info_t *info, graph_element_t *graph);

#endif /* ERRORS */
