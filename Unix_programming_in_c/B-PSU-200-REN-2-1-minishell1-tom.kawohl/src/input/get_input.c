/*
** EPITECH PROJECT, 2022
** input
** File description:
** get_input
*/
#include "src.h"

char *get_input(char **env)
{
    char *input = NULL;
    size_t input_limit = 4096;
    int input_length = 0;
    input = malloc(sizeof(char) * input_limit);
    char *exit_str = "exit\n";

    if (getline(&input, &input_limit, stdin) == -1) {
        write(2, exit_str, my_strlen(exit_str));
        if (input)
            free(input);
        if (is_env_freeable(FALSE) == TRUE)
            free_array_str2d(env);
        exit(get_return(FALSE));
    }
    input_length = my_strlen(input);
    input[input_length - 1] = '\0';
    input = input_clean_space(input);
    return (input);
}
