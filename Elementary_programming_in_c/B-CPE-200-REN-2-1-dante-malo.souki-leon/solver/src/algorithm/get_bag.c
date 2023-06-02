/*
** EPITECH PROJECT, 2023
** get_bag
** File description:
** get_bag
*/

#include "src.h"

static int detect_bag_y(src_t *gn, int data)
{
    int x = gn->cp->x;
    int y = gn->cp->y;

    if (y == 0 && data == -1)
        return 1;
    if (gn->cp->map[gn->cp->y + data] == NULL)
        return 1;
    if (gn->cp->map[y + data][x] == gn->cp->map[y][x] - 1)
        return 0;
    return 1;
}

static int detect_bag_x(src_t *gn, int data)
{
    int x = gn->cp->x;
    int y = gn->cp->y;

    if (x == 0 && data == -1)
        return 1;
    if (gn->cp->map[gn->cp->y][gn->cp->x + data] == '\0')
        return 1;
    if (gn->cp->map[y][x + data] == gn->cp->map[y][x] - 1)
        return 0;
    return 1;
}

static int move_case_x(src_t *gn)
{
    if (detect_bag_x(gn, 1) == 0){
        gn->cp->map[gn->cp->y][gn->cp->x] = -2;
        gn->cp->x++;
        gn->cp->mcase--;
        return 1;
    }
    if (detect_bag_x(gn, -1) == 0){
        gn->cp->map[gn->cp->y][gn->cp->x] = -2;
        gn->cp->x--;
        gn->cp->mcase--;
        return 1;
    }
    return 0;
}

static int move_case_y(src_t *gn)
{
    if (detect_bag_y(gn, 1) == 0){
        gn->cp->map[gn->cp->y][gn->cp->x] = -2;
        gn->cp->y++;
        gn->cp->mcase--;
        return 1;
    }
    if (detect_bag_y(gn, -1) == 0){
        gn->cp->map[gn->cp->y][gn->cp->x] = -2;
        gn->cp->y--;
        gn->cp->mcase--;
        return 1;
    }
    return 0;
}

int get_bag(src_t *gn)
{
    if (move_case_x(gn) == 1)
        return 1;
    if (move_case_y(gn) == 1)
        return 1;
    return 0;
}
