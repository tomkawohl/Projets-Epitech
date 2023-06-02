/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "src.h"

static void malloc_struct(src_t *gn)
{
    gn->ch = malloc(sizeof(base_t) * (1));
    if (gn->ch == NULL)
        exit(84);
    gn->cp = malloc(sizeof(compteur_t) * (1));
    if (gn->cp == NULL)
        exit(84);
}

int main(int ac, char **av)
{
    src_t *gn = malloc(sizeof(src_t));
    if (ac != 2)
        return 1;
    if (gn == NULL)
        return 84;
    malloc_struct(gn);
    gn->cp->check = 0;
    gn->cp->x = 0;
    gn->cp->y = 0;
    get_map(gn, av[1]);
    gn->cp->map[gn->cp->y][gn->cp->x]++;
    gn->cp->mcase = 2;
    while (1){
        solve_maze(gn);
        if (gn->cp->map[gn->cp->y][gn->cp->x + 1] == '\0'
        && gn->cp->map[gn->cp->y + 1] == NULL)
            break;
    }
    draw_map(gn);
    return 0;
}
