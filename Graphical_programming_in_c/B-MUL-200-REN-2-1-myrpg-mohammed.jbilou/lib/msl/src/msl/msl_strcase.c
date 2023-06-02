/*
** EPITECH PROJECT, 2023
** msl_str_lowcase
** File description:
** msl_str_lowcase
*/

#include "msl.h"

void msl_verif_param(int n)
{
    if (n != 1 && n != 0){
        write(2, "Error: Invalid parameter from msl_strcase\n", 43);
        write(2, "Try with 1 or 0\n", 17);
        return;
    }
}

char *msl_strcase(char *str, int n)
{
    char a = 'A';
    char z = 'Z';
    int res = 32;

    msl_verif_param(n);
    if (n == 1){
        a = 'a';
        z = 'z';
        res *= -1;
    }
    if (str == NULL || str[0] == '\0'){
        write(2, "Error: Invalid string from msl_strupcase\n", 42);
        return str;
    }
    for (int i = 0; str[i]; i++){
        if (str[i] >= a && str[i] <= z)
            str[i] += res;
    }
    return str;
}
