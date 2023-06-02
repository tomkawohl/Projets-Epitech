/*
** EPITECH PROJECT, 2022
** env
** File description:
** add_value_var_env
*/
#include "src.h"

void add_value_var_env(char ***env, char *name, char *value)
{
    if (is_var_in_env(env[0], name) == FALSE) {
        add_name_var_env(env, name);
        assign_var_env(&env, name, value);
    } else {
        assign_var_env(&env, name, value);
    }
}
