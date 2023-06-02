/*
** EPITECH PROJECT, 2022
** gui_info/
** File description:
** gui_info_destroy
*/
#include "my_paint.h"

void button_main_destroy(button_main_t *button)
{
    if (button->main != NULL)
        button_destroy(button->main);
    if (button->down != NULL)
        button_destroy_all(button->down);
    free(button);
}

void gui_info_destroy(gui_info_t *gui_info)
{
    for (U_INT i = 0; gui_info->topbar[i] != NULL; i++)
        button_main_destroy(gui_info->topbar[i]);
    priority_button_destroy(gui_info->prio);
    free(gui_info->topbar);
    free(gui_info);
}
