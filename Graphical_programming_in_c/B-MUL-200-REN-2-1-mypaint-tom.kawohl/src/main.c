/*
** EPITECH PROJECT, 2023
** src/main.c
** File description:
** main file for project
*/

#include "my_paint.h"

int main(UNUSED int argc, UNUSED char **argv)
{
    paint_t *info = malloc(sizeof(struct paint_t));

    init(info);
    while (info->running != TERMINATE) {
        run(info);
    }
    info_destroy(info);
    return 0;
}
