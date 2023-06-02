/*
** EPITECH PROJECT, 2022
** src
** File description:
** get_change_status
*/
#include "src.h"

int get_change_status(int set_status, int get)
{
    static int status = 0;
    if (get == TRUE)
        return (status);
    status = set_status;
    return (-1);
}
