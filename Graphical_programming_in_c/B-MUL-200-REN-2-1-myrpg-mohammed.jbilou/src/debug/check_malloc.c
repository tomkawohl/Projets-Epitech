/*
** EPITECH PROJECT, 2022
** check_malloc
** File description:
** malloc
*/
/**
 * @file check_malloc.c
 *
 * @brief check if a malloc has failed
 *
 * @date 04/04/2023
*/
#include "src.h"

int check_malloc(void *alloc, char const *filename)
{
    if (alloc == NULL){
        my_printf("malloc failed in file [%s]\n", filename);
        return 1;
    }
    return 0;
}
