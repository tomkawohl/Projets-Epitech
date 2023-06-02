/*
** EPITECH PROJECT, 2022
** env
** File description:
** verify_env
*/
#include "src.h"

void verify_env(char ***env)
{
    if (is_env_freeable(FALSE) == FALSE) {
        add_name_var_env(env, "a");
        delete_var_env(&env, "a");
    }
}
