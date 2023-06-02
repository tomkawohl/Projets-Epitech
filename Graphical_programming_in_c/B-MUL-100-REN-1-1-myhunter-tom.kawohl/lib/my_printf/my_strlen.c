/*
** EPITECH PROJECT, 2022
** my_putstr
** File description:
** my_putstr
*/
#include "my_printf.h"
int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0'){
        i++;
    }
    return (i);
}
