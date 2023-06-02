/*
** EPITECH PROJECT, 2022
** env
** File description:
** z_getenv
*/
#include "src.h"

char *z_get_env(char **env, char *search)
{
    char **tmp = NULL;
    char *res = NULL;
    int search_length = my_strlen(search);
    int i = 0;
    if (env == NULL || search == NULL)
        return (NULL);
    tmp = env;
    while (tmp[i] != NULL) {
        if (my_strncmp(env[i], search, search_length) == 0) {
            res = str_recat(res, tmp[i] + (search_length + 1));
            return (res);
        }
        i++;
    }
    return (NULL);
}
