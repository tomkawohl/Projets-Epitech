/*
** EPITECH PROJECT, 2022
** main_menu
** File description:
** main_menu
*/
#include "my_all.h"
#include "my_printf.h"
#include "src.h"
#include <string.h>

void destroy_gamemenu(text_t *score, g_time_t *t, g_time_t *t_move)
{
    sfFont_destroy(score->police);
    sfText_destroy(score->score);
    sfText_destroy(score->nbr);
    sfClock_destroy(t->clock);
    sfClock_destroy(t_move->clock);
}

object_t *init_gamemenu(void)
{
    object_t *tab = {0};
    tab = malloc(sizeof(object_t) * 6);
    memset(tab, 0, (sizeof(object_t) * 6) );
    tab[5].tab_end = 1;
    sfVector2f size = {3.2, 3.2};
    sfVector2f size_dirge = {0.7, 0.7};
    create_sprite(&tab[0], "assets/sprites/street.png", size);
    create_sprite(&tab[1], "assets/sprites/ennemy_dirge.png", size_dirge);
    create_sprite(&tab[2], "assets/sprites/ennemy_dirge.png", size_dirge);
    create_sprite(&tab[3], "assets/sprites/ennemy_dirge.png", size_dirge);
    create_sprite(&tab[4], "assets/sprites/ennemy_dirge.png", size_dirge);
    init_ennemy(tab);

    return (tab);
}

void update_gamemenu(sfRenderWindow *win, object_t *tab)
{
    g_time_t t = {0};
    g_time_t t_move = {0};
    sfEvent event;
    t.clock = sfClock_create();
    t_move.clock = sfClock_create();
    text_t score = create_text();
    int points = 1;
    int chance = 3;
    while (sfRenderWindow_isOpen(win)) {
        analyse_events_game(win, event, tab, &points);
        animate_all(tab, &t, 123, 357.5);
        move_all(tab, &chance, &t_move);
        sfRenderWindow_clear(win, sfBlack);
        draw_all(win, tab);
        draw_points(win, points, score);
        draw_text(win, score);
        sfRenderWindow_display(win);
        is_end(win, chance, points);
    }
    destroy_gamemenu(&score, &t, &t_move);
}

void game(sfRenderWindow *window)
{
    object_t *tab = init_gamemenu();
    update_gamemenu(window, tab);
    destroy_ressources(tab);
}
