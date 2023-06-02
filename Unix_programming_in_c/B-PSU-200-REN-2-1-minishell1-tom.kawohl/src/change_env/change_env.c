/*
** EPITECH PROJECT, 2022
** src
** File description:
** change_env
*/
#include "src.h"

char **change_env(char **env, char *input)
{
    int status = get_change_status(0, TRUE);
    char **arg = NULL;

    if (env == NULL || input == NULL)
        return (env);
    if (status == RESET || status == -1)
        return (env);
    arg = str_to_word_array(input);
    if (!arg)
        return (env);
    if (status == ADD_NAME)
        return (change_env_add_name(env, arg));
    if (status == ASSIGN)
        return (change_env_assign(env, arg));
    if (status == DELETE)
        return (change_env_delete(env, arg));
    if (status == PWD)
        return (change_pwd_env(env, arg));
    return (env);
}
