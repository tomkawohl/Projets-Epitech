/*
** EPITECH PROJECT, 2022
** env
** File description:
** m_is_var_in_env
*/
#include "src.h"

int verif_var(char *var, int search_length)
{
    if (var[search_length] == '=')
        return (TRUE);
    return (FALSE);
}

int m_is_var_in_env(char **env, char *search)
{
    if (search == NULL || env == NULL)
        return (FALSE);
    char **tmp = NULL;
    int search_length = my_strlen(search);
    int i = 0;
    tmp = env;
    while (tmp[i] != NULL) {
        if (my_strncmp(tmp[i], search, search_length) == 0) {
            return (verif_var(tmp[i], search_length));
        }
        i++;
    }
    return (FALSE);
}
