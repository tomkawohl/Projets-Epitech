/*
** EPITECH PROJECT, 2023
** file_map
** File description:
** update_idx_arg
*/
/**
 * @file update_idx_arg.c
 *
 * @brief Update idx_arg, help with file to map
 *
 * @date 10/04/2023
*/
#include "src.h"
#include "lib_will.h"

void update_idx_arg(char *str, u_int *idx_arg)
{
    while (str[*idx_arg] != '\0' && str[*idx_arg] != COORD_DEL_CHAR)
        (*idx_arg)++;
    (*idx_arg)++;
}
