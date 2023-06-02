/*
** EPITECH PROJECT, 2022
** env
** File description:
** get_index_var
*/
#include "src.h"

int get_index_var(char **env, char *name)
{
    int i = 0;
    int name_length = 0;
    if (name == NULL || env == NULL)
        return (-1);
    name_length = my_strlen(name);
    while (env[i] != NULL) {
        if (my_strncmp(env[i], name, name_length) == 0)
            return (i);
        i++;
    }
    return (-1);
}
