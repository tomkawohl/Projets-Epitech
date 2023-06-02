/*
** EPITECH PROJECT, 2022
** manage_mouse
** File description:
** manage_mouse
*/

#include "my_all.h"
#include "my_printf.h"
#include "src.h"

void click_start(sfRenderWindow *window, sfEvent event, object_t *tab)
{
    sfVector2i mouse_vec = sfMouse_getPositionRenderWindow(window);
    sfVector2f button_pos = sfSprite_getPosition(tab[1].sprite);
    sfMusic *start;
    if (mouse_vec.x >= button_pos.x && mouse_vec.x <= button_pos.x + 180) {
        if (mouse_vec.y >= button_pos.y && mouse_vec.y <= button_pos.y + 70
        && event.type == sfEvtMouseButtonPressed){
            start = sfMusic_createFromFile("assets/musics/start.ogg");
            sfMusic_play(start);
            game(window);
            sfMusic_destroy(start);
            }
    }
}
