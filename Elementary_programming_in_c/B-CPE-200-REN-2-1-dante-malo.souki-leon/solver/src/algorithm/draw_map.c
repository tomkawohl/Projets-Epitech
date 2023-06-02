/*
** EPITECH PROJECT, 2023
** draw_map
** File description:
** draw_map
*/

#include "src.h"

static void draw_path(src_t *gn, register int i)
{
    for (register int j = 0; gn->cp->map[i][j] != '\0'; j++){
        if (gn->cp->map[i][j] == 1)
            write(1, "*", 1);
        if (gn->cp->map[i][j] == -1)
            write(1, "X", 1);
        if (gn->cp->map[i][j] == -2)
            write(1, "*", 1);
        if (gn->cp->map[i][j] > 1)
            write(1, "o", 1);
    }
    write(1, "\n", 1);
}

void draw_map(src_t *gn)
{
    for (register int i = 0; gn->cp->map[i] != NULL; i++){
        draw_path(gn, i);
    }
}
