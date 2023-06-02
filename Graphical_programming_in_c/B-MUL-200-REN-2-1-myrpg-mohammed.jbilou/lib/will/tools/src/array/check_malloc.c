/*
** EPITECH PROJECT, 2022
** array
** File description:
** check_malloc
*/
#include "../../include/tools.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>

bool verify_malloc(void *ptr, const char *str)
{
    if (ptr != NULL)
        return (true);
    print_error(str);
    print_error("allocation failed\n");
    return (false);
}
