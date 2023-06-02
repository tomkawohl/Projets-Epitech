/*
** EPITECH PROJECT, 2022
** int
** File description:
** int_is_overflow
*/
#include "../../include/tools.h"
#include <unistd.h>

int int_is_overflow(long long value)
{
    long long int_max = 2147483647;
    long long int_min = -2147483647;
    if (value > int_max || value < int_min)
        return (TRUE);
    return (FALSE);
}
