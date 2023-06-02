/*
** EPITECH PROJECT, 2023
** description
** File description:
** handle_help.c
*/
/**
 * @file handle_help.c
 *
 * @brief Handle help
 *
 * @date 23/04/2023
*/
#include "lib_will.h"
#include <stdlib.h>

void handle_help(void)
{
    char *str = file_to_str_stat("src/description/help.txt");

    if (!str)
        return;
    write(1, str, str_len(str));
    free(str);
}
