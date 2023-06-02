/*
** EPITECH PROJECT, 2022
** %s
** File description:
** %s
*/
#include <stdarg.h>
#include "my_printf.h"
#include <stdlib.h>
int conv_smaj(va_list list, const char * format, int i, int *count)
{
    int j = 0;
    char *str = malloc(sizeof(char) * 100);
    str = va_arg(list, char*);
    while (str[j] != '\0'){
        if (str[j] >= 'A' && str[j] <= 'Z'){
            my_putchar(str[j]);
            (*count)++;
        }
        if (str[j] >= 'a' && str[j] <= 'z'){
            my_putchar(str[j]);
            (*count)++;
        }
if (!(str[j] >= 'A' && str[j] <= 'Z' || str[j] >= 'a' && str[j] <= 'z')){
            my_putchar(92);
            (*count)++;
            my_put_nbr_base(str[j], "8", count);
        }
        j++;
    }
    return (0);
}
