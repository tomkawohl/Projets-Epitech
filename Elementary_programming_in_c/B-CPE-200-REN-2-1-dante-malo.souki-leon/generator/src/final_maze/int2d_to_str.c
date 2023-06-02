/*
** EPITECH PROJECT, 2022
** src
** File description:
** int2d_to_str
*/
#include "src.h"

void print_last_line(int x)
{
    char *str = NULL;
    int i = 1;
    str = malloc(sizeof(char) * x + 2);
    if (!str)
        return;
    str[0] = '\n';
    while ( i < (x - 1)) {
        str[i] = WALL;
        i++;
    }
    str[i] = WAY;
    i++;
    str[i] = WAY;
    str[x + 1] = '\0';
    write(1, str, my_strlen(str));
    free(str);
}

void int2d_to_str(int **tab, int x, int y)
{
    y -= 2;
    x -= 2;
    long long int tab_size = (x * y + y);
    if (!tab || tab_size <= 0)
        return;
    if (is_x_impair(FALSE, TRUE) == FALSE)
        print_maze_x_impair(tab, x, y, tab_size);
    else
        print_maze_x_pair(tab, x, y, tab_size);
    return;
}
