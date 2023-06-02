/*
** EPITECH PROJECT, 2022
** ennemy.c
** File description:
** ennemy.c
*/
#include "my_all.h"
#include "my_printf.h"
#include "src.h"
#include <time.h>

void init_ennemy(object_t *tab)
{
    sfVector2f pos[4] = {{0.0, 0.0}, {-400.0 , 200.0},
    {-600.0, 400.0}, {-800.0, 200.0}};
    int i = 1;
    while (tab[i].tab_end != 1) {
        tab[i].rect = set_sprite(tab[i].sprite, 119, 106);
        tab[i].pv = 2;
        sfSprite_setPosition(tab[i].sprite, pos[i -1]);
        i++;
    }
}

void destroy_ennemy(object_t *tab, int i)
{
    if (tab[i].pv == 0) {
        tab[i].is_dead = 1;
        tab[i].pv = 2;
    }
}

void random_pos(sfVector2f *pos, int random_nb)
{
    if (random_nb >= 0 && random_nb <= 1000000000) {
        (*pos).y = 200.0;
        return;
    }
    if (random_nb >= 1000000000 && random_nb <= 2000000000) {
        (*pos).y = 400.0;
        return;
    }
    (*pos).y = 0.0;

}

void move_enemy(object_t *tab, int i, int *chance, g_time_t *t_move)
{
    int random_nb = 0;
    srand( time( NULL ) );
    sfVector2f pos_init = {-100.0, 0.0};
    sfVector2f pos = sfSprite_getPosition(tab[i].sprite);
    pos.x += 5;
    if (t_move->seconds > 0.0001) {
        sfSprite_setPosition(tab[i].sprite, pos);
    }
    if (pos.x >= 870.0) {
        random_nb = rand();
        random_pos(&pos_init, random_nb);
        sfSprite_setPosition(tab[i].sprite, pos_init);
        if (tab[i].is_dead == 0)
            (*chance)--;
        tab[i].is_dead = 0;
    }
}
