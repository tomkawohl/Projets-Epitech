/*
** EPITECH PROJECT, 2022
** tools/pencil
** File description:
** tool_event
*/
#include "my_paint.h"

void set_rightbar(paint_t *info, int tool_activ)
{
    info->gui->rightbar_display = true;
    info->gui->rightbar_activ = true;
    for (U_INT i = 1; info->gui->rightbar[i] != NULL; i++) {
        info->gui->rightbar[i]->main_display = false;
        info->gui->rightbar[i]->main_activ = false;
        info->gui->rightbar[i]->down_activ = false;
        info->gui->rightbar[i]->down_display = false;
    }
    info->gui->rightbar[tool_activ]->main_display = true;
    info->gui->rightbar[tool_activ]->main_activ = true;
    info->gui->rightbar[tool_activ]->down_activ = true;
    info->gui->rightbar[tool_activ]->down_display = true;
}

void tool_event(sfEvent event, paint_t *info)
{
    static int can_select_pencil = true;
    static int can_select_eraser = true;

    if (sfKeyboard_isKeyPressed(sfKeyP) && can_select_pencil == true) {
        set_rightbar(info, 1);
        info->tools->pencil->is_activ = true;
        info->tools->pencil->is_eraser = false;
        can_select_pencil = false;
    }
    if (sfKeyboard_isKeyPressed(sfKeyE) && can_select_eraser == true) {
        set_rightbar(info, 2);
        info->tools->pencil->is_activ = false;
        info->tools->pencil->is_eraser = true;
        can_select_eraser = false;
    }
    if (event.type == sfEvtKeyReleased) {
        can_select_pencil = true;
        can_select_eraser = true;
    }
}
