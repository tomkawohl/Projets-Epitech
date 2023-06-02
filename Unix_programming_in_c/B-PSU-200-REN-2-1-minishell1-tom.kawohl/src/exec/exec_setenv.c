/*
** EPITECH PROJECT, 2022
** exec
** File description:
** exec_setenv
*/
#include "src.h"

int check_error_setenv(unsigned int nb_arg, char **arg)
{
    char *error = "setenv: Too many arguments.\n";
    int error_nb = 1;
    if (nb_arg <= 3)
        return (FALSE);
    get_return(&error_nb);
    free_array_str2d(arg);
    write(2, error, my_strlen(error));
    return (TRUE);
}

int is_setenv(char *input)
{
    if (my_strncmp(input, "setenv", 6) != 0)
        return (FALSE);
    if (input[6] != '\0' && input[6] != SPACE)
            return (FALSE);
    return (TRUE);
}

int exec_setenv(char *input, char **env)
{
    char ** arg = NULL;
    unsigned int nb_arg = 0;
    if (!input) return (FALSE);
    if (is_setenv(input) != TRUE)
        return (FALSE);
    arg = str_to_word_array(input);
    if (arg == NULL) return (TRUE);
    nb_arg = count_arg(arg);
    if (check_error_setenv(nb_arg, arg))
        return (TRUE);
    if (nb_arg == 1) print_env(env);
    if (nb_arg == 2)
        get_change_status(ADD_NAME, FALSE);
    if (nb_arg == 3)
        get_change_status(ASSIGN, FALSE);
    free_array_str2d(arg);
    return (TRUE);
}
