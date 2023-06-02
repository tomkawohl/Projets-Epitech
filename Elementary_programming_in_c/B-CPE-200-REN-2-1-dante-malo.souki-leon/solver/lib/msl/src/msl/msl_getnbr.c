/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** my_getnbr
*/

#include "msl.h"

int msl_overflow(char *str)
{
    int nb = msl_atoi(str);
    char *verif = msl_itoa(nb);
    int j = 0;

    for (; str[j] == '-' || str[j] == '+'; j++);
    for (; str[j] == '0'; j++);
    if (str[j] == '\0')
        j--;
    if (msl_strcmp(verif, &str[j]) == 1){
        write(2, "Error: Overflow from msl_overflow detected\n", 44);
        return TRUE;
    }
    return FALSE;
}

int msl_atoi(char *str)
{
    int res = 0;
    int mult = 1;
    int j = 0;
    int sign = 1;

    if (str == NULL || str[0] == '\0'){
        write(2, "Error: Invalid string from msl_atoi\n", 37);
        return ERROR;
    }
    for (; str[j] == '-' || str[j] == '+'; j++){
        if (str[j] == '-')
            sign *= -1;
    }
    for (; str[j] <= '9' && str[j] >= '0'; j++);
    for (int i = j - 1; str[i] <= '9' && str[i] >= '0'; i--, mult *= 10)
        res += (str[i] - 48) * mult;
    return res * sign;
}

int msl_getnbr(char *str)
{
    int i = 0;

    if (str == NULL || str[i] == '\0'){
        write(2, "Error: Invalid string from msl_getnbr\n", 39);
        return ERROR;
    }
    if (str[0] == '\0')
        return FALSE;
    for (; (str[i] > '9' || str[i] < '0')
    && str[i] != '-' && str[i] != '+'; i++);
    if (msl_overflow(&str[i]) == 1)
        return ERROR;
    return msl_atoi(&str[i]);
}
