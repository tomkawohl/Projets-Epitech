/*
** EPITECH PROJECT, 2022
** manage_events_game
** File description:
** manage_events_game
*/
#include "my_all.h"
#include "my_printf.h"
#include "src.h"

int click_ennemy(sfVector2i mouse_vec, sfEvent event, object_t *tab, int i)
{
    int hitbox_x = 80;
    int hitbox_y = 72;
    if ((mouse_vec.x >= tab[i].coord.x &&
    mouse_vec.x <= tab[i].coord.x + hitbox_x) &&
    (mouse_vec.y >= tab[i].coord.y &&
    mouse_vec.y <= tab[i].coord.y + hitbox_y)) {
        if (event.type == sfEvtMouseButtonPressed) {
            tab[i].pv--;
            destroy_ennemy(tab, i);
            return (1);
        }
    }
    return (0);
}

void check_pos(sfVector2i mouse_vec, sfEvent event, object_t *tab, int *score)
{
    int i = 1;
    while (tab[i].tab_end != 1) {
        tab[i].coord = sfSprite_getPosition(tab[i].sprite);
        if (tab[i].is_dead == 0 &&
        (click_ennemy(mouse_vec, event, tab, i) == 1)) {
                (*score) += 100;
        }
        i++;
    }
}

void analyse_events_game(sfRenderWindow *window, sfEvent event,
object_t *tab, int *score)
{
    while (sfRenderWindow_pollEvent(window, &event)){
    sfVector2i mouse_vec = sfMouse_getPositionRenderWindow(window);
    check_pos(mouse_vec, event, tab, score);
    if (event.type == sfEvtClosed)
        close_window(window);
    }
}
