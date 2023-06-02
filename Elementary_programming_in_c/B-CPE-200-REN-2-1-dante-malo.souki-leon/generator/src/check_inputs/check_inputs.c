/*
** EPITECH PROJECT, 2022
** check_inputs
** File description:
** check_inputs
*/
#include "src.h"

int check_inputs(int ac, char **av)
{
    if (check_ac(ac) == FALSE)
        return (FALSE);
    if (check_av(ac, av) == FALSE)
        return (FALSE);
    if (check_value_inputs(av) == FALSE)
        return (FALSE);
    return (TRUE);
}
