/*
** EPITECH PROJECT, 2022
** file
** File description:
** file_to_str_stat
*/
#include "../../include/tools.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int stat_file(const char *filename)
{
    struct stat info;
    int is_valid = 0;
    is_valid = stat(filename, &info);
    if (is_valid == -1)
        return (0);
    if (S_ISREG(info.st_mode))
        return (info.st_size);
    return (0);
}

char *file_to_str_stat(char *filename)
{
    char *buffer = {0};
    int size = stat_file(filename);
    int is_read_valid = 0;
    if (size <= 0)
        return (NULL);
    int fd = open(filename, O_RDONLY);
    if (fd == -1)
        return (NULL);
    buffer = malloc(sizeof(char) * size + 1);
    is_read_valid = read(fd, buffer, size);
    if (is_read_valid == -1) {
        free(buffer);
        return (NULL);
    }
    close (fd);
    buffer[size] = '\0';
    return (buffer);
}
