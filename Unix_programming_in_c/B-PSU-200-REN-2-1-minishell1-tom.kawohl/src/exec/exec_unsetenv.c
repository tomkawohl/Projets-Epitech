/*
** EPITECH PROJECT, 2022
** exec
** File description:
** exec_unsetenv
*/
#include "src.h"

int check_error(int arg_nb, char **arg)
{
    char *error = "unsetenv: Too few arguments.\n";
    int error_nb = 1;
    if (arg_nb <= 1) {
        get_return(&error_nb);
        write(2, error, my_strlen(error));
        free_array_str2d(arg);
        return (TRUE);
    }
    return (FALSE);
}

int is_unsetenv(char *input)
{
    if (my_strncmp(input, "unsetenv", 8) != 0)
        return (FALSE);
    if (input[8] != '\0' && input[8] != SPACE)
            return (FALSE);
    return (TRUE);
}

int exec_unsetenv(char *input)
{
    char **arg = NULL;
    unsigned int arg_nb = 0;
    if (input == NULL)
        return (FALSE);
    if (is_unsetenv(input) != TRUE)
        return (FALSE);
    arg = str_to_word_array(input);
    if (arg == NULL)
        return (TRUE);
    arg_nb = count_arg(arg);
    if (check_error(arg_nb, arg))
        return (TRUE);
    get_change_status(DELETE, FALSE);
    free_array_str2d(arg);
    return (TRUE);
}
/*
int exec_setenv(char *input, char **env)
{
    char ** arg = NULL;
    unsigned int nb_arg = 0;
    if (!input) return (FALSE);
    if (is_setenv(input) != TRUE)
        return (FALSE);
    arg = str_to_word_array(input);
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
*/
