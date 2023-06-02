/*
** EPITECH PROJECT, 2023
** scene
** File description:
** handle_save_pos
*/
/**
 * @file handle_save_pos.c
 *
 * @brief Handle the pos of save or current
 *
 * @date 21/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "game_actor.h"
#include "test_area.h"
#include "player.h"

void update_idx_title(char *str, u_int *i)
{
    while (str[*i] != '\0' && str[*i] != ':')
        (*i)++;
    (*i)++;
}

void handle_save_pos(game_t *gm)
{
    u_int i = save_find(gm->save, "POS PL");
    u_int j = 0;
    sfVector2i pos = {0, 0};

    update_idx_title(gm->save[i], &j);
    pos.x = my_getnbr_int(&(gm->save[i][j]));
    update_idx_arg(gm->save[i], &j);
    pos.y = my_getnbr_int(&(gm->save[i][j]));
    w_printf("x = %d and y = %d\n", pos.x, pos.y);
    player_set_pos(gm, pos);
}
