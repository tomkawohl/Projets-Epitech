/*
** EPITECH PROJECT, 2022
** src
** File description:
** main
*/
/**
 * @file main.c
 *
 * @brief Has main function of the project
 *
 * @date 28/03/2023
*/
#include "src.h"
#include "parser.h"

/* notes : optimisation if ants can move on differents ways */

static void display_final_result(info_t *info)
{
    my_printf("#number_of_ants\n");
    my_printf("%d\n", info->nb_ants);
    my_printf("#rooms\n");
    file_parser_display(info->file_to_parse, true);
    my_printf("#tunnels\n");
    file_parser_display(info->file_to_parse, false);
}

static void init_tab(info_t *info, graph_element_t *graph)
{
    u_int way = 0;
    u_int i = 1;

    info->way[0] = 0;
    while (way != graph->nb_vertices - 1) {
        info->way[i] = find_way(graph, way);
        way = info->way[i];
        i++;
    }
    info->way[i] = -1;
}

int main(void)
{
    graph_element_t *graph = NULL;
    info_t *info = malloc(sizeof(info_t));

    if (check_malloc(info, "main.c") == TRUE)
        return 84;
    if (get_info_from_files(info) == false) {
        destroy_program(info, NULL);
        return 84;
    }
    graph = graph_init(info);
    if (graph == NULL) {
        destroy_program(info, NULL);
        return (84);
    }
    info->way = malloc(sizeof(int) * info->nb_cells);
    init_tab(info, graph);
    display_final_result(info);
    handle_lem_in(graph, info);
    open_window(info, graph);
    destroy_program(info, graph);
    return (EXIT_SUCCESS);
}
