/*
** EPITECH PROJECT, 2022
** src
** File description:
** m_get_index_var
*/
#include "src.h"

int is_var(char *var, char *name, int name_length)
{
    if (my_strncmp(var, name, name_length) == 0) {
        if (var[name_length] == '=')
            return (TRUE);
    }
    return (FALSE);
}

int m_get_index_var(char **env, char *name)
{
    int i = 0;
    int name_length = 0;
    char **tmp = NULL;

    if (env == NULL || name == NULL)
        return (-1);
    tmp = env;
    name_length = my_strlen(name);
    while (tmp[i] != NULL) {
        if (is_var(tmp[i], name, name_length))
            return (i);
        i++;
    }
    return (-1);
}
