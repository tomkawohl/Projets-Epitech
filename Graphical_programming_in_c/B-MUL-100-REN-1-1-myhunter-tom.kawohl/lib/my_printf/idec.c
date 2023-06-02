/*
** EPITECH PROJECT, 2022
** idec
** File description:
** idec
*/
#include "my_printf.h"
int idec(int n)
{
    int i = 1;

    while (n >= 9){
        n /= 10;
        i++;
    }
    return (i);
}
