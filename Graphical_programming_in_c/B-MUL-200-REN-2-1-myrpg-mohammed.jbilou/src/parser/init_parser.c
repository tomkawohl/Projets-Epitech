/*
** EPITECH PROJECT, 2023
** init_parser.c
** File description:
** init_parser
*/

#include "parser.h"
#include "src.h"

static void free_tab(char **tab)
{
    if (!tab)
        return;
    for (size_t i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}

char *init_buffer(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    struct stat info;
    char *buffer = NULL;

    if (fd == -1){
        my_printf("FAILED TO OPEN FILE\n");
        return NULL;
    }

    stat(filepath, &info);
    buffer = malloc(sizeof(char) * (info.st_size + 1));
    buffer[info.st_size] = '\0';
    read(fd, buffer, info.st_size);
    close(fd);
    return buffer;
}

static size_t count_nb_lines(char const *buffer)
{
    size_t count = 0;

    for (size_t i = 0; buffer[i]; i++){
        if (buffer[i] == '\n')
            count++;
    }
    return count;
}

static void parse_file(parser_t *pars, char *buffer, char **parser, char **tab)
{
    sfVector2f pos_rect = {0, 0};
    sfVector2f pos_text = {0, 0};
    sfVector2f size = {0, 0};
    size_t type = 0;

    for (size_t i = 0; tab[i]; i++) {
        parser = str_to_array_separator(tab[i], ';', ';');
        pars[i].type = my_atoi(parser[0]);
        pars[i].name = msl_strcpy(parser[1]);
        pos_rect.x = my_atoi(parser[2]);
        pos_rect.y = my_atoi(parser[3]);
        pars[i].pos_rect = pos_rect;
        pos_text.x = my_atoi(parser[4]);
        pos_text.y = my_atoi(parser[5]);
        pars[i].pos_text = pos_text;
        size.x = my_atoi(parser[6]);
        size.y = my_atoi(parser[7]);
        pars[i].size = size;
        free_tab(parser);
    }
}

void init_parser(game_t *gm, char const *filepath)
{
    char *buffer = init_buffer(filepath);
    size_t nb_lines = 0;
    char **tab = NULL;
    char **parser = NULL;

    if (buffer == NULL)
        return;
    nb_lines = count_nb_lines(buffer);
    tab = str_to_array_separator(buffer, '\n', '\n');
    gm->pars = malloc(sizeof(parser_t) * (nb_lines + 1));
    parse_file(gm->pars, buffer, parser, tab);
}
