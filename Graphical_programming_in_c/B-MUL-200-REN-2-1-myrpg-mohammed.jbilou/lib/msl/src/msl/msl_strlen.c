/*
** EPITECH PROJECT, 2023
** my_strlen
** File description:
** my_strlen
*/

#include "msl.h"

int msl_strlen(char const *str)
{
    int i = 0;

    if (str == NULL){
        write(2, "Error: Invalid string from msl_strlen\n", 39);
        return ERROR;
    }
    for (; str[i] != '\0'; i++);
    return i;
}
