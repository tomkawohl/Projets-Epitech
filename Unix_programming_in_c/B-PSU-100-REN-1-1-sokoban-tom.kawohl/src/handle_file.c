/*
** EPITECH PROJECT, 2022
** handle_file
** File description:
** handle_file
*/

#include "../include/my_all.h"
#include "../include/my.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
int stat_file(char *filename)
{
    struct stat info;
    int is_valid = 0;
    is_valid = stat(filename, &info);
    if (is_valid == -1) return (0);
    return (info.st_size);
}

char *handle_file(char *filename, int size)
{
    char *buffer = {0};
    int is_read_valid = 0;
    int fd = open(filename, O_RDONLY);
    buffer = malloc(sizeof(char) * size + 1);
    if (fd == -1) exit (84);
    is_read_valid = read(fd, buffer, size);
    if (is_read_valid == -1) exit(84);
    close(fd);
    return (buffer);
}
