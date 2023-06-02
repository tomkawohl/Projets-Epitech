/*
** EPITECH PROJECT, 2022
** src
** File description:
** events
*/
#include "src.h"

w_event_t init_w_event(void)
{
    w_event_t w_event;
    w_event.display_hitbox = TRUE;
    w_event.display_sprite = TRUE;
    return (w_event);
}

void handle_events(sfRenderWindow *win, w_event_t *w_event)
{
    while (sfRenderWindow_pollEvent(win, &(w_event->event))) {
            if (w_event->event.type == sfEvtClosed) {
                sfRenderWindow_close(win);
            }
            if (w_event->event.type == sfEvtKeyPressed &&
            w_event->event.key.code == sfKeyL) {
                w_event->display_hitbox *= -1;
            }
            if (w_event->event.type == sfEvtKeyPressed &&
            w_event->event.key.code == sfKeyS) {
                w_event->display_sprite *= -1;
            }

        }
}
