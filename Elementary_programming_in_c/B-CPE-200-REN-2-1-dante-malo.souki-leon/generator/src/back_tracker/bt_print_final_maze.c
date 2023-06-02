/*
** EPITECH PROJECT, 2022
** src
** File description:
** bt_print_final_maze
*/
#include "src.h"

void bt_fill_line_str(char *str, maze_data_t *maze_data, int *str_i, int i)
{
    int j = 0;
    while (j < maze_data->m_x) {
        if (maze_data->maze[i][j] == 1)
            str[*str_i] = WALL;
        else
            str[*str_i] = WAY;
        (*str_i)++;
        j++;
    }
    str[*str_i] = '\n';
    (*str_i)++;
}

void bt_fill_str(char *str, maze_data_t *maze_data)
{
    register int i = 0;
    int str_i = 0;
    while (i < maze_data->m_y) {
        bt_fill_line_str(str, maze_data, &str_i, i);
        i++;
    }
}

void bt_print_final_maze(maze_data_t *maze_data)
{
    char *str = NULL;
    U_INT count = (U_INT)(maze_data->m_x * maze_data->m_y + maze_data->m_y);

    count -= 1;
    if (count == 0)
        return;
    str = malloc(sizeof(char) * (count + 1));
    if (!str)
        return;
    bt_fill_str(str, maze_data);
    str[count] = '\0';
    write(1, str, my_strlen(str));
    free(str);
    return;
}
