/*
** EPITECH PROJECT, 2022
** struct.h
** File description:
** struct.h
*/

#include <SFML/Graphics.h>
#include <stdlib.h>
#include <SFML/Config.h>
#include <SFML/Window/Mouse.h>

#ifndef STRUCT_H_
    #define STRUCT_H_
typedef struct object_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfVector2f origin;
    sfVector2f scale;
    sfVector2f coord;
    float rotation;
    float anim;
    int tab_end;
    int pv;
    int is_dead;
} object_t;

typedef struct window_s {
    sfVideoMode mode;
    sfRenderWindow *win;
    sfEvent event;
} window_t;


typedef struct g_time_s {
    sfClock *clock;
    sfTime time;
    float seconds;
} g_time_t;


typedef struct game_s {
    object_t *object;
    sfVector2f mouse;
} game_t;

typedef struct text_s {
    sfFont *police;
    sfText *score;
    sfText *nbr;
} text_t;

#endif /* STRUCT_H_ */
