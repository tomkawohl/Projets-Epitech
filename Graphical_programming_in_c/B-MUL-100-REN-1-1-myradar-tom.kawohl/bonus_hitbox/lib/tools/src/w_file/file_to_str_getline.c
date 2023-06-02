/*
** EPITECH PROJECT, 2022
** file
** File description:
** file_to_str_getline
*/
#include "../../include/tools.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

char *file_to_str_getline(const char *filename)
{
    char *line = NULL;
    char *res = {0};
    int is_to_dup = 0;
    size_t size = 0;
    ssize_t read = 0;
    if (!filename) return (NULL);
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
        return (NULL);
    while ((read = getline(&line, &size, fp)) != -1) {
        if (is_to_dup == 1 && line != NULL)
            res = str_recat(res, line);
        if (is_to_dup == 0 && line != NULL) {
            res = my_strdup(line);
            is_to_dup = 1;
        }
    }
    if (line) free(line);
    fclose(fp);
    return (res);
}
