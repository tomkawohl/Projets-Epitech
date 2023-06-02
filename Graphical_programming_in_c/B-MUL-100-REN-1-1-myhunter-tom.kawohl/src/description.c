/*
** EPITECH PROJECT, 2022
** description
** File description:
** description
*/
#include "my_all.h"
#include "my_printf.h"
#include "src.h"

int is_arg_valid(char *str)
{
    int nb = my_strlen(str);
    if (nb != 2)
        return (0);
    if (str[0] != '-')
        return (0);
    if (str[1] != 'h')
        return (0);
    return (1);
}

void description(char *str)
{
    if (is_arg_valid(str) == 0)
        return;
    my_printf("my_hunter:\n-Kill enemies by ");
    my_printf("clicking on them with your mouse, ");
    my_printf("one click is 1 damage, be careful: they have 2 hp\n");
    my_printf("-If they manage to pass more than three times, ");
    my_printf("it's loose and the score is displayed\n");
    my_printf("Good luck\n");
}
