/*
** EPITECH PROJECT, 2022
** src
** File description:
** simulation
*/
#include "src.h"

void destroy(text_t *timer, w_clock_t *w_clock,
            sfRenderWindow *win, object_t *map)
{
    text_destroy(timer);
    sfClock_destroy(w_clock->clock);
    sfRenderWindow_destroy(win);
    obj_destroy(map);
}

int update(sfRenderWindow *win, w_event_t *w_event,
            w_clock_t *w_clock, object_t **planes)
{
    handle_events(win, w_event);
    w_clock_update(w_clock);
    planes_move(planes, w_clock);
    return (planes_display(win, planes, *(w_event)));
}

void simulation(object_t **airplanes, object_t **towers)
{
    sfRenderWindow *win = init_window(1920, 1080, 32);
    object_t *map = obj_sprite_create("assets/sprites/map.png");
    w_event_t w_event = init_w_event();
    w_clock_t *w_clock = w_clock_init();
    text_t timer = text_create();
    int is_end = FALSE;
    if (!win) return;
    while (sfRenderWindow_isOpen(win)) {
        sfRenderWindow_clear(win, sfBlack);
        sfRenderWindow_drawSprite(win, map->sprite, NULL);
        is_end = update(win, &w_event, w_clock, airplanes);
        towers_displays(win, towers, w_event);
        draw_text(win, timer, w_clock);
        sfRenderWindow_display(win);
        collision(airplanes, towers);
        if (is_end == TRUE) sfRenderWindow_close(win);
    }
    destroy(&timer, w_clock, win, map);
    return;
}
