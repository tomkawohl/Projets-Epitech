/*
** EPITECH PROJECT, 2022
** handling_errros
** File description:
** handling_errors
*/
#include "../include/my_all.h"
#include "../include/my.h"
#include "../include/src.h"
#include "../include/struct.h"
#include <curses.h>
#include <stdlib.h>

int check_p(char *str)
{
    int nb_player = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == PLAYER) {
            nb_player++;
        }
    }
    if (nb_player == 1)
        return (1);
    return (0);
}

int is_char_valid(char c)
{
    char *valid = "XOP# ";
    for (int j = 0; valid[j] != '\0'; j++) {
        if (c == valid[j] || c == 10) {
            return (1);
        }
    }
    return (0);
}

int handling_errors(char *str, char **tab)
{
    int loc = get_many_loc(tab);
    int boxe = get_many_boxe(tab);
    if (loc > boxe)
        return (-1);
    if (check_p(str) == 0)
        return (-1);
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_char_valid(str[i]) == 0) {
            return (-1);
        }
    }
    return (0);
}
