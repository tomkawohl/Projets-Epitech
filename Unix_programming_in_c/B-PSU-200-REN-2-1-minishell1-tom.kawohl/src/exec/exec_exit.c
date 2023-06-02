/*
** EPITECH PROJECT, 2022
** exec
** File description:
** exec_exit
*/
#include "src.h"

void check_exit_input(char **input_exit, int *can_print_exit)
{
    int exit_nb = 0;
    int error_nb = 1;
    char *error = "exit: Expression Syntax.\n";
    if (str_is_num(input_exit[1]) == FALSE) {
        (*can_print_exit) = FALSE;
        write(2, error, my_strlen(error));
        get_return(&error_nb);
        return;
    }
    exit_nb = my_getnbr_int(input_exit[1]);
    get_return(&exit_nb);

}

int check_exit(char *input, int *can_print_exit)
{
    char **input_exit = NULL;
    int nb_arg = 0;
    input_exit = str_to_word_array(input);
    if (!input_exit)
        return (TRUE);
    if (my_strlen(input_exit[0]) != 4) {
        free_array_str2d(input_exit);
        return (FALSE);
    }
    nb_arg = count_arg(input_exit);
    if (nb_arg > 1) {
        if (input_exit[1] != NULL)
            check_exit_input(input_exit, can_print_exit);
    }
    free_array_str2d(input_exit);
    return (TRUE);
}

int exec_exit(char *input)
{
    int can_print_exit = TRUE;
    if (!input)
        return (FALSE);
    if (my_strncmp(input, "exit", 4) != 0)
        return (FALSE);
    if (check_exit(input, &can_print_exit) == FALSE)
        return (FALSE);
    if (can_print_exit)
        z_printf("exit\n");
    return (TRUE);
}
