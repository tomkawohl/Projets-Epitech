/*
** EPITECH PROJECT, 2022
** manage_window
** File description:
** manage_window
*/

#include "my_all.h"
#include "my_printf.h"
#include "src.h"

void init_window(window_t *win, int width, int height, int bpp)
{
    win->mode.width = width;
    win->mode.height = height;
    win->mode.bitsPerPixel = bpp;
    win->win = sfRenderWindow_create(win->mode, "win",
    sfClose, NULL);
}

void close_window(sfRenderWindow *window)
{
    sfRenderWindow_close(window);
}
