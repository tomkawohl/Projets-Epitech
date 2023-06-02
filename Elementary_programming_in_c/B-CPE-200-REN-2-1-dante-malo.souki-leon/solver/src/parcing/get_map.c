/*
** EPITECH PROJECT, 2023
** get_map
** File description:
** get_map
*/

#include "src.h"

static int get_line_size(int i, char *buffer)
{
    int count = 0;

    for (;buffer[i] != '\n' && buffer[i] != '\0'; i++){
        count++;
    }
    return count;
}

static int get_nb_line(char *buffer)
{
    register int count = 1;

    for (register int i = 0; buffer[i] != '\0'; i++){
        if (buffer[i] == '\n')
            count++;
    }
    return count;
}

static int **str_to_nb_array(char *buffer)
{
    int x = 0;
    int y = 0;
    int col_size = 0;
    int line = get_nb_line(buffer);
    int **array = malloc(sizeof(int *) * (line + 1));

    for (int i = 0; y != line; y++, i++){
        x = 0;
        col_size = get_line_size(i, buffer);
        array[y] = malloc(sizeof(int) * (col_size + 1));
        array[y][col_size] = '\0';
        for (;buffer[i] != '\n' &&
        buffer[i] != '\0'; i++, x++){
            array[y][x] = buffer[i];
        }
    }
    array[line] = NULL;
    return array;
}

static void convert_buffer(char **buffer)
{
    for (register int i = 0; (*buffer)[i]; i++){
        if ((*buffer)[i] == 'X')
            (*buffer)[i] = -1;
        if ((*buffer)[i] == '*')
            (*buffer)[i] = 1;
        if ((*buffer)[i] != 'X' && (*buffer)[i] != '*' && (*buffer)[i] != '\n')
            exit(84);
    }
}

void get_map(src_t *gn, char *file_path)
{
    int fd = open(file_path, O_RDONLY);
    char *buffer = NULL;
    struct stat st;
    size_t size = 0;

    if (stat(file_path, &st) == -1 || S_ISDIR(st.st_mode) == 1 || fd == -1)
        exit(84);
    size = st.st_size;
    buffer = malloc(sizeof(char) * (size + 1));
    if (buffer == NULL)
        exit(84);
    buffer[size] = '\0';
    read(fd, buffer, size);
    convert_buffer(&buffer);
    gn->cp->map = str_to_nb_array(buffer);
    free(buffer);
}
