/*
** EPITECH PROJECT, 2022
** piercing
** File description:
** piercing
*/

#include "msl.h"

void psl_piercing(char *disp, int i, va_list list)
{
    if (disp[i + 1] == 's')
        msl_putstr(va_arg(list, char*));
    if (disp[i + 1] == 'd')
        msl_put_nbr(va_arg(list, int));
    if (disp[i + 1] == 'c')
        msl_putchar(va_arg(list, int));
    if (disp[i + 1] == 't')
        psl_show_tab(va_arg(list, char**));
    if (disp[i + 1] == 'i')
        psl_show_int(va_arg(list, int**));
    if (disp[i + 1] == 'l')
        psl_show_chain(va_arg(list, base_t*));
}
