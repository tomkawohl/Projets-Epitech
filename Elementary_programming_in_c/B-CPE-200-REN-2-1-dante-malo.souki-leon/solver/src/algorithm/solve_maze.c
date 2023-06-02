/*
** EPITECH PROJECT, 2023
** solve_maze
** File description:
** solve_maze
*/

#include "src.h"

static int get_case_x(src_t *gn, int data)
{
    if (gn->cp->x == 0 && data == -1)
        return 0;
    if (gn->cp->map[gn->cp->y][gn->cp->x + 1] == '\0')
        return 0;
    if (gn->cp->map[gn->cp->y][gn->cp->x + data] == 1){
        gn->cp->x += data;
        gn->cp->map[gn->cp->y][gn->cp->x] += gn->cp->mcase;
        gn->cp->mcase++;
        return 1;
    }
    return 0;
}

static int get_case_y(src_t *gn, int data)
{
    if (gn->cp->y == 0 && data == -1)
        return 0;
    if (gn->cp->map[gn->cp->y + 1] == NULL)
        return 0;
    if (gn->cp->map[gn->cp->y + data][gn->cp->x] == 1){
        gn->cp->y += data;
        gn->cp->map[gn->cp->y][gn->cp->x] += gn->cp->mcase;
        gn->cp->mcase++;
        return 1;
    }
    return 0;
}

static int check_other_case(src_t *gn, int check)
{
    if (check == 0){
        if (get_case_y(gn, 1) == 1)
            return 1;
    }
    if (check == 1){
        if (get_case_x(gn, 1) == 1)
            return 1;
    }
    if (check == 2){
        if (get_case_y(gn, -1) == 1)
            return 1;
    }
    if (check == 3){
        if (get_case_x(gn, -1) == 1)
            return 1;
    }
    return 0;
}

static int get_cond(src_t *gn)
{
    int check = 0;

    for (; check != 4; check++){
        if (check_other_case(gn, check) == 1)
            break;
    }
    if (check == 4)
        return 0;
    return 1;
}

void solve_maze(src_t *gn)
{
    int x = gn->cp->x;
    int y = gn->cp->y;

    if (gn->cp->check != 0 && x == 0 && y == 0){
        write(1, "no solution found\n", 18);
        exit(1);
    }
    if (get_cond(gn) == 0)
        get_bag(gn);
    gn->cp->check = 10;
}
