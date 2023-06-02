/*
** EPITECH PROJECT, 2022
** parser
** File description:
** opens the file and puts it in a buffer
*/
/**
 * @file file_to_buffer.c
 *
 * @brief opens the file and puts it in a buffer
 *
 * @date 29/03/2023
*/
#include "src.h"
#include "parser.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include "errors.h"

static void free_all(char *buffer, char *file, char **tab)
{
    free(buffer);
    free(file);
    free_array_str2d(tab);
}

static void get_buffer(info_t *info, char **tab, char *file, char *buffer)
{
    if (file) {
        tab = str_to_array_separator(file, '\n', ' ');
        info->file_to_parse = str_to_array_separator(file, '\n', '\n');
        info->file = copy_array(tab);
        free_all(buffer, file, tab);
    }
}

bool file_to_info(info_t *info)
{
    size_t n = 1;
    char *buffer = malloc(sizeof(char) * n);
    char *file = NULL;
    char **tab = NULL;

    if (check_malloc(buffer, "file_to_buffer.c") == 1)
        return false;
    while (getline(&buffer, &n, stdin) != -1) {
        file = str_cat(file, "");
        file = str_cat(file, buffer);
    }
    if (n == 1)
        return false;
    get_buffer(info, tab, file, buffer);
    return true;
}
