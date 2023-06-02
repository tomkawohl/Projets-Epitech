/*
** EPITECH PROJECT, 2023
** msl_strcapitalize
** File description:
** msl_strcapitalize
*/

#include "msl.h"

char *msl_strcapitalize(char *str)
{
    if (str == NULL || str[0] == '\0'){
        write(2, "Error: Invalid string from msl_strcapitalize\n", 46);
        return str;
    }
    for (int i = 0; str[i]; i++){
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
    }
    for (int i = 1; str[i]; i++){
        if (msl_charisalpha(str[i - 1]) == FALSE
        && msl_charisalpha(str[i]) == TRUE)
            str[i] -= 32;
    }
    if (str[0] >= 'a' && str[0] <= 'z')
        str[0] -= 32;
    return str;
}
