/*
** EPITECH PROJECT, 2022
** all_sprites
** File description:
** all_sprites
*/
#include "my_all.h"
#include "my_printf.h"
#include "src.h"

void draw_all(sfRenderWindow *win, object_t *tab)
{
    int i = 0;
    while (tab[i].tab_end != 1) {
        if (tab[i].is_dead == 0)
            sfRenderWindow_drawSprite(win, tab[i].sprite, NULL);
        i++;
    }
}

void animate_all(object_t *tab, g_time_t *t, int offset, int max_value)
{
    int i = 1;
    t->time = sfClock_getElapsedTime(t->clock);
    t->seconds = t->time.microseconds / 1000000.0;
        if (t->seconds > 0.25) {
            while (tab[i].tab_end != 1) {
                move_rect(&(tab[i].rect), offset, max_value);
                sfSprite_setTextureRect(tab[i].sprite, tab[i].rect);
                i++;
            }
            sfClock_restart(t->clock);
        }
}

void move_all(object_t *tab, int *chance, g_time_t *t_move)
{
    int i = 1;
    t_move->time = sfClock_getElapsedTime(t_move->clock);
    t_move->seconds = t_move->time.microseconds / 1000000.0;
    while (tab[i].tab_end != 1) {
        move_enemy(tab, i, chance, t_move);
        i++;
    }
    if (t_move->seconds > 0.0001) {
        sfClock_restart(t_move->clock);
    }
}
