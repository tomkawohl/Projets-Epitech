/*
** EPITECH PROJECT, 2023
** show file.c
** File description:
** print the file content
*/

#include "src.h"

static void print_tunnels(char **file, char **pars)
{
    for (size_t i = 0; file[i]; i++) {
        if (str_contains_char(file[i], '-') != true)
            continue;
        pars = str_to_array_separator(file[i], '-', ' ');
        if (pars[0] && pars[1]){
            my_printf("%s-", pars[0]);
            my_printf("%s\n", pars[1]);
        }
        if (pars)
            free_array_str2d(pars);
    }
}

static void print_rooms(char **file, char **pars)
{
    for (size_t i = 0; file[i]; i++){
        if ((str_contains_char(file[i], '-') == true)
        || (file[i][0] == '#' && file[i][1] != '#'))
            continue;
        pars = str_to_array_separator(file[i], ' ', '\n');
        if (pars[0] && my_strcmp(pars[0], "##end") == 0)
            my_printf("%s\n", pars[0]);
        if (pars[0] && my_strcmp(pars[0], "##start") == 0)
            my_printf("%s\n", pars[0]);
        if (pars[0] && pars[1] && pars[2]) {
            my_printf("%s ", pars[0]);
            my_printf("%s ", pars[1]);
            my_printf("%s\n", pars[2]);
        }
        if (pars)
            free_array_str2d(pars);
    }
}

void file_parser_display(char **file, bool type)
{
    char **pars = NULL;

    if (type == true)
        print_rooms(file, pars);
    if (type == false)
        print_tunnels(file, pars);
}
