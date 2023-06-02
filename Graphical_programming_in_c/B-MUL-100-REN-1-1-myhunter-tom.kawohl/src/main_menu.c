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

object_t *init_mainmenu(void)
{
    object_t *tab = {0};
    tab = malloc(sizeof(object_t) * 3);
    memset(tab, 0, (sizeof(object_t) * 3));
    sfVector2f size = {2.5, 2.5};
    sfVector2f size_button = {0.3, 0.3};
    sfVector2f coord_button = {300, 250};
    create_sprite(&tab[0], "assets/sprites/city.png", size);
    create_sprite(&tab[1], "assets/sprites/start_button.png", size_button);
    tab[0].anim = 0.5;
    tab[0].rect = set_sprite(tab[0].sprite, 688, 272);
    sfSprite_setPosition(tab[1].sprite, coord_button);
    tab[2].tab_end = 1;
    return (tab);
}

void update_mainmenu(window_t *win, object_t *tab)
{
    g_time_t t = {0};
    sfEvent event;
    sfMusic *music =
    sfMusic_createFromFile("assets/musics/an_ancient_king.ogg");
    t.clock = sfClock_create();
    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
    while (sfRenderWindow_isOpen(win->win)) {
        while (sfRenderWindow_pollEvent(win->win, &event)){
            analyse_events(win->win, event, tab);
        }
        animate_sprite(&tab[0], &t, 5, 380);
        sfRenderWindow_clear(win->win, sfBlack);
        sfRenderWindow_drawSprite(win->win, tab[0].sprite, NULL);
        sfRenderWindow_drawSprite(win->win, tab[1].sprite, NULL);
        sfRenderWindow_display(win->win);
    }
    sfMusic_destroy(music);
    sfClock_destroy(t.clock);
}

void destroy_mainmenu(window_t *menu, object_t *tab)
{
    destroy_ressources(tab);
    sfRenderWindow_destroy(menu->win);
}
