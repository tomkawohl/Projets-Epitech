/*
** EPITECH PROJECT, 2022
** tab_2d
** File description:
** tab_2d
*/

#include "../include/my_all.h"
#include "../include/my.h"
#include "../include/src.h"
#include <stdlib.h>
int free_tab2d(char **ptr, char *str)
{
    int j = 0;
    int line_size = get_line_size(str);
    while (j < line_size) {
        free(ptr[j]);
        j++;
    }
    free(ptr);
    return (0);
}
