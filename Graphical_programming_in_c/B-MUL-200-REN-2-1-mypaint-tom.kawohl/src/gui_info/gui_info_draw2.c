/*
** EPITECH PROJECT, 2023
** gui_info_draw2.c
** File description:
** gui_info_draw2
*/

#include "my_paint.h"

void gui_info_draw(paint_t *info)
{
    if (info->gui->topbar_display == true) {
        for (U_INT i = 0; info->gui->topbar[i] != NULL; i++) {
            gui_button_draw(info->gui->topbar[i], info);
        }
    }
    if (info->gui->rightbar_display == true) {
        rightbar_display(info);
    }
    return;
}
