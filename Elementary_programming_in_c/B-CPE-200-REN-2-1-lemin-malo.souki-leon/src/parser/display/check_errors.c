/*
** EPITECH PROJECT, 2023
** check erros
** File description:
** check_errors
*/

#include "src.h"
#include "parser.h"

bool check_if_name_alredy_exists(char *name, link_t *link, bool room)
{
    size_t room_repetition = 0;

    for (; link != NULL; link = link->next) {
        if (my_strcmp(link->data, name) == 0)
            room_repetition++;
    }
    if (room == true){
        if (room_repetition > 1)
            return false;
    } else {
        if (room_repetition == 0)
            return false;
    }
    return true;
}

bool check_same_coordinates(char **pars, info_t *info, size_t i)
{
    char **pars_j = NULL;

    for (size_t j = 0; j < i; j++) {
        pars_j = str_to_array_separator(info->file_to_parse[j], ' ', '\n');
        if (pars_j[0] && pars_j[1] && pars_j[2]
        && my_getnbr_int(pars[1]) == my_getnbr_int(pars_j[1])
        && my_getnbr_int(pars[2]) == my_getnbr_int(pars_j[2]))
            return false;
        free_array_str2d(pars_j);
    }
    return true;
}

void diplay_error_tunnels(info_t *info, char **pars, int i, link_t *link)
{
    my_printf("#tunnels\n");
    for (; info->file_to_parse[i]; i++) {
        if (str_contains_char(info->file_to_parse[i], '-') == false)
            return;
        pars = str_to_array_separator(info->file_to_parse[i], '-', ' ');
        if (!pars || pars[0] == NULL || pars[1] == NULL)
            continue;
        if (check_if_name_alredy_exists(pars[0], link, false) == false)
            return;
        if (check_if_name_alredy_exists(pars[1], link, false) == false)
            return;
        if (info->file_to_parse[i][0] != '#' && pars[0] && pars[1]) {
            my_printf("%s-%s\n", pars[0], pars[1]);
        }
    }
}

bool check_rooms(char **pars, size_t *nb_start, size_t *nb_end)
{
    if (my_strcmp(pars[0], START) == 0 && *nb_start > 0)
        return false;
    if (my_strcmp(pars[0], START) == 0)
        *nb_start += 1;
    if (my_strcmp(pars[0], END) == 0 && *nb_end > 0)
        return false;
    if (my_strcmp(pars[0], END) == 0)
        *nb_end += 1;
    return true;
}

bool add_to_link(char **pars, link_t *link)
{
    if (pars[0] && pars[1] && pars[2] && pars[0][0] != '#' && link != NULL)
        add_link_end(&link, str_cpy(pars[0]));
    if (pars[0] && pars[1] && pars[2] && pars[0][0] != '#' && link == NULL)
        link = create_list(link, str_cpy(pars[0]));
    if (check_if_name_alredy_exists(pars[0], link, true) == false)
        return false;
    return true;
}
