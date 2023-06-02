/*
** EPITECH PROJECT, 2022
** window
** File description:
** init_window
*/
#include "../../include/w_csfml.h"

sfRenderWindow *init_window(UINT width, UINT height, UINT bpp)
{
    sfVideoMode mode = {width, height, bpp};
    sfRenderWindow *win;
    win = sfRenderWindow_create(mode, "window", sfClose, NULL);
    if (!win)
        return (NULL);
    return (win);
}
