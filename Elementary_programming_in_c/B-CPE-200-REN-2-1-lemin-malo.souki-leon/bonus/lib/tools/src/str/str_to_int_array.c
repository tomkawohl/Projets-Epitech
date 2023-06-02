/*
** EPITECH PROJECT, 2022
** str
** File description:
** str_to_int_array
*/
#include "../../include/tools.h"
#include <unistd.h>
#include <stdlib.h>

void next_int(const char *str, int *i)
{
    if (!str)
        return;
    while (char_is_num(str[*i]) == TRUE && str[*i] != '\0')
        (*i)++;
}

int *str_to_int_array(const char *str)
{
    int i = 0;
    int j = 0;
    if (!str) return (NULL);
    unsigned int nb_int = str_count_int(str);
    if (nb_int == 0) return (NULL);
    int *result = malloc(sizeof(int) * nb_int);
    if (!result) return (NULL);
    while (j < nb_int) {
        if (char_is_num(str[i])) {
            result[j] = my_getnbr_int(&(str[i]));
            next_int(str, &i);
            j++;
        }
        while (char_is_num(str[i]) != TRUE && str[i] != '\0')
            i++;
        if (str[i] == '\0')
            break;
    }
    return (result);
}
