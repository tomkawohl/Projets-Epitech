/*
** EPITECH PROJECT, 2022
** is_end
** File description:
** is_end
*/
#include "my_all.h"
#include "my_printf.h"
#include "src.h"
#include <string.h>

object_t *init_endmenu(void)
{
    object_t *tab = {0};
    tab = malloc(sizeof(object_t) * 2);
    memset(tab, 0, (sizeof(object_t) * 2) );
    sfVector2f size = {3.2, 3.2};
    create_sprite(&tab[0], "assets/sprites/end.png", size);
    tab[1].tab_end = 1;
    return (tab);
}

void update_endmenu(sfRenderWindow *win, object_t *tab, int points)
{
    sfEvent event;
    text_t score = create_text();
    sfVector2f coord_score = {300, 250};
    sfVector2f coord_nbr = {405, 250};
    sfText_setPosition(score.score, coord_score);
    sfText_setPosition(score.nbr, coord_nbr);
    while (sfRenderWindow_isOpen(win)) {
        while (sfRenderWindow_pollEvent(win, &event)){
            analyse_end_game(win, event);
        }
        sfRenderWindow_clear(win, sfBlack);
        sfRenderWindow_drawSprite(win, tab[0].sprite, NULL);
        draw_points(win, points, score);
        sfRenderWindow_drawText(win, score.score, NULL);
        sfRenderWindow_drawText(win, score.nbr, NULL);
        sfRenderWindow_display(win);
    }
    sfFont_destroy(score.police);
    sfText_destroy(score.score);
    sfText_destroy(score.nbr);
}

void is_end(sfRenderWindow *win, int chance, int points)
{
    if (chance == 0) {
        object_t *tab = init_endmenu();
        update_endmenu(win, tab, points);
        destroy_ressources(tab);
    }
}
