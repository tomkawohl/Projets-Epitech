/*
** EPITECH PROJECT, 2022
** src/graph
** File description:
** graph_create
*/
/**
 * @file graph_create.c
 *
 * @brief Has functions to create a graph structure
 *
 * @date 28/03/2023
*/
#include "src.h"

static int is_graph_allocated(graph_element_t *element)
{
    if (element == NULL) {
        print_error("Graph_create.c : graph struct allocation failed\n");
        return (false);
    }
    return (true);
}

static int is_adjacency_list_allocated(adjacency_list_t *list)
{
    if (list == NULL) {
        print_error("Graph_create.c : adjacency list allocation failed\n");
        return (false);
    }
    return (true);
}

static char **graph_init_name(unsigned int nb_vertices)
{
    char **names = malloc(sizeof(char *) * (nb_vertices + 1));

    if (names == NULL) {
        print_error("Graph_create.c : array names allocaton failed\n");
        return (NULL);
    }
    for (u_int i = 0; i < (nb_vertices + 1); i++) {
        names[i] = NULL;
    }
    return (names);
}

graph_element_t *graph_create(unsigned int nb_vertices)
{
    unsigned int i = 0;
    graph_element_t *element;

    element = malloc(sizeof(*element));
    if (is_graph_allocated(element) == false)
        return (NULL);
    element->nb_vertices = nb_vertices;
    element->neighbours = malloc(sizeof(adjacency_list_t *) * (nb_vertices));
    if (is_adjacency_list_allocated(element->neighbours) == false) {
        free(element);
        return (NULL);
    }
    for (; i < nb_vertices; i++)
        element->neighbours[i].start = NULL;
    element->names = graph_init_name(nb_vertices);
    if (element->names == NULL) {
        graph_destroy(element);
        return (NULL);
    }
    return (element);
}
