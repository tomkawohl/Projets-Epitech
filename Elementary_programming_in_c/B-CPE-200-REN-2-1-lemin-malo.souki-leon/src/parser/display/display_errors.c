/*
** EPITECH PROJECT, 2023
** display_errors.c
** File description:
** display_errors
*/

#include "src.h"
#include "parser.h"

static bool check_nb_rooms(info_t *info, int i, char **pars, size_t *nb_rooms)
{
    if (pars[0][0] != '#' && pars[1] && pars[2]
    && my_strstr(info->file_to_parse[i - 1], START) == NULL
    && my_strstr(info->file_to_parse[i - 1], END) == NULL)
        *nb_rooms += 1;
    if (check_same_coordinates(pars, info, i) == false)
        return false;
    return true;
}

static void init_pars(parser_t *pars)
{
    pars->link = NULL;
    pars->nb_end = 0;
    pars->nb_rooms = 0;
    pars->nb_start = 0;
    pars->pars = NULL;
}

bool display_error_parsed(parser_t *pars, info_t *info, size_t i)
{
    if (str_contains_char(info->file_to_parse[i], '-')
    && (pars->nb_start != 1 || pars->nb_end != 1))
        return false;
    pars->pars = str_to_array_separator(info->file_to_parse[i], ' ', '\n');
    if (pars->pars[0][0] != '#'
    && str_is_num(pars->pars[0]) == FALSE && pars->pars[1] == NULL)
        return false;
    if (pars->pars == NULL || pars->pars[0][0] == '\0')
        return false;
    if (check_rooms(pars->pars, &pars->nb_start, &pars->nb_end) == false)
        return false;
    if (add_to_link(pars->pars, pars->link) == false)
        return false;
    if (check_nb_rooms(info, i, pars->pars, &pars->nb_rooms) == false)
        return false;
    return true;
}

static void prin_start_end_rooms(parser_t *pars)
{
    if (my_strcmp(pars->pars[0], "##end") == 0)
        my_printf("##end\n");
    else if (my_strcmp(pars->pars[0], "##start") == 0)
        my_printf("##start\n");

    if (my_strcmp(pars->pars[0], "##end") != 0
        && my_strcmp(pars->pars[0], "##start") != 0
        && pars->pars[0] && pars->pars[1] && pars->pars[2])
        my_printf("%s %s %s\n", pars->pars[0], pars->pars[1], pars->pars[2]);
}

void display_error(info_t *info, parser_t *pars)
{
    size_t i = info->idx_to_start;

    init_pars(pars);
    if (info->idx_to_print == 1 || info->idx_to_print == 0)
        return;
    my_printf("#number_of_ants\n");
    my_printf("%d\n", info->nb_ants);
    my_printf("#rooms\n");
    for (; info->file_to_parse[i]; i++) {
        if (str_contains_char(info->file_to_parse[i], '-')
        && pars->nb_start == 1 && pars->nb_end == 1)
            break;
        if (display_error_parsed(pars, info, i) == false)
            return;
        prin_start_end_rooms(pars);
        free_array_str2d(pars->pars);
    }
    if (pars->nb_rooms == 0)
        return;
    diplay_error_tunnels(info, pars->pars, i, pars->link);
}
