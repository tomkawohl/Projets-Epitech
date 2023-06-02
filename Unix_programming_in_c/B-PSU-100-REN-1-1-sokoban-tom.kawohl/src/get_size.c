/*
** EPITECH PROJECT, 2022
** get_size
** File description:
** get_size
*/
#include "../include/my_all.h"
#include "../include/my.h"
#include "../include/src.h"
#include <curses.h>
#include <stdlib.h>

int get_colone_max(char *str)
{
    int colone_size = 0;
    int colone_max = 0;
    int i = 0;
    while (str[i] != '\0') {
        colone_size = 0;
        while (str[i] != '\n' && str[i] != '\0') {
            colone_size++;
            i++;
        }
        if (str[i + 1] == '\0')
            break;
        i++;
        if (colone_max < colone_size) {
            colone_max = colone_size;
        }
    }
    return (colone_max);
}

int get_colone_size(char *str, int i)
{
    int colone_size = 0;
    while (str[i] != '\n' && str[i] != '\0') {
        colone_size++;
        i++;
    }
    return (colone_size);
}

int get_line_size(char *str)
{
    int line_size = 0;
    int i = 0;
    int j = 0;
    while (str[i] != '\0') {
        j = 0;
        while (str[i] != '\n' && str[i] != '\0') {
            i++;
            j++;
        }
        line_size++;
        if (str[i + 1] == '\0')
            break;
        i++;
    }
    return (line_size);
}
