/*
** EPITECH PROJECT, 2022
** print
** File description:
** print
*/

#include "msl.h"

void psl_display(char *disp, int i)
{
    if (disp[i] != '%' && disp[i - 1] != '%')
        write(1, &disp[i], 1);
}

void psl_printf(char *disp, ...)
{
    va_list list;
    va_start(list, disp);
    if (disp == NULL || disp[0] == '\0')
        write(2, "Invalid arguments\n", 19);
    for (int i = 0; disp[i] != '\0'; i++){
        psl_display(disp, i);
        if (disp[i] == '%'){
            psl_piercing(disp, i, list);
        }
    }
}
