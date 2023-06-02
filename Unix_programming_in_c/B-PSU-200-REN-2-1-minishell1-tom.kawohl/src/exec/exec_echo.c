/*
** EPITECH PROJECT, 2022
** exec
** File description:
** exec_echo
*/
#include "src.h"

int exec_echo(char *input)
{
    if (!input)
        return (FALSE);
    if (my_strncmp(input, "echo $?", 6) != 0)
        return (FALSE);
    z_printf("%d\n", get_return(NULL));
    return (TRUE);
}
