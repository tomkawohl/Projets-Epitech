/*
** EPITECH PROJECT, 2022
** src
** File description:
** print_maze_x_pair
*/
#include "src.h"


void fill_line_x_pair(int **tab, char *str, coord_t limit, int *str_i)
{
    int i = get_i_str(NULL);
    int j = 1;
    while (j < (limit.x + 1)) {
        if (tab[i][j] == -1)
            str[*str_i] = WALL;
        else
            str[*str_i] = WAY;
        (*str_i)++;
        j++;
    }
    if (i < (limit.y))
        str[*str_i] = WALL;
    else
        str[*str_i] = WAY;
    (*str_i)++;
    str[*str_i] = '\n';
    (*str_i)++;
}

void fill_str_x_pair(int **tab, char *str, coord_t limit)
{
    int i = 1;
    int str_i = 0;
    while (i < (limit.y + 1)) {
        get_i_str(&i);
        fill_line_x_pair(tab, str, limit, &str_i);
        i++;
    }
    return;
}

void print_maze_x_pair(int **tab, int x, int y, int tab_size)
{
    coord_t limit = {x, y};
    char *str = NULL;
    tab_size += y;
    str = malloc(sizeof(char) * (tab_size));
    if (!str)
        return;
    fill_str_x_pair(tab, str, limit);
    str[tab_size - 1] = '\0';
    write(1, str, my_strlen(str));
    if (is_y_impair(FALSE, TRUE)) {
        x++;
        print_last_line(x);
    }
    free(str);
    return;
}
