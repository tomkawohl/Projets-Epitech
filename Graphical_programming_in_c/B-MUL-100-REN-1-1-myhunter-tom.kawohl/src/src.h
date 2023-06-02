/*
** EPITECH PROJECT, 2022
** src.h
** File description:
** src.h
*/

#ifndef SRC_H_
    #define SRC_H_

    #include "struct.h"
    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <SFML/Config.h>
    #include "my_all.h"
    #include "my_printf.h"
    #include <SFML/Window/Mouse.h>
    #include <SFML/System/Clock.h>
    #include <SFML/Audio.h>

/* window */
void init_window(window_t *win, int width, int height, int bpp);

/* main menu */
void description(char *str);
void destroy_mainmenu(window_t *menu, object_t *tab);
object_t *init_mainmenu(void);
void update_mainmenu(window_t *win, object_t *tab);

/* handle sprite */
sfIntRect set_sprite(sfSprite *, int, int);
void move_rect(sfIntRect *, int, int);
void create_sprite(object_t *obj, char const *path, sfVector2f size);
void animate_sprite(object_t *obj, g_time_t *t, int offset, int max_value);

/* handle all sprites */
void animate_all(object_t *tab, g_time_t *t, int offset, int max_value);
void draw_all(sfRenderWindow *win, object_t *tab);
void move_all(object_t *tab, int *chance, g_time_t *t_move);

/* destroy */
void destroy_object(object_t *obj);
void destroy_ressources(object_t *tab);

/* mouse */
void click_start(sfRenderWindow *window, sfEvent event, object_t *tab);

/* game */
void game(sfRenderWindow *window);
void analyse_events_game(sfRenderWindow *window,
sfEvent event, object_t *tab, int *score);

/* text */
text_t create_text(void);
void draw_points(sfRenderWindow *win, int points, text_t score);
void draw_text(sfRenderWindow *win, text_t score);

/* handle ennemy */
void move_enemy(object_t *tab, int i, int *chance, g_time_t *t_move);
void destroy_ennemy(object_t *tab, int i);
void init_ennemy(object_t *tab);

/* end */
void is_end(sfRenderWindow *win, int chance, int points);
void analyse_end_game(sfRenderWindow *window, sfEvent event);

void analyse_events(sfRenderWindow *, sfEvent, object_t *tab);
void close_window(sfRenderWindow *);

#endif /* SRC_H_ */
