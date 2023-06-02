/*
** EPITECH PROJECT, 2022
** tools/pencil
** File description:
** help_press_left
*/
#include "my_paint.h"

void ok_click(paint_t *info)
{
    priority_button_remove_all(info->gui->prio);
}

void add_ok_button(paint_t *info)
{
    button_info_t button_ok = {0};
    button_ok.color = TOP_BG;
    button_ok.font_size = FONT_SIZE;
    button_ok.hover = NULL;
    button_ok.is_activ = true;
    button_ok.pos = (sfVector2f){info->window_size.x / 2,
        info->window_size.y / 2 + 250.0};
    button_ok.pressed_left = ok_click;
    button_ok.size = (sfVector2f){50.0, 50.0};
    button_ok.text = str_cat(button_ok.text, "Ok");
    priority_button_add(info->gui->prio, button_ok);
    free(button_ok.text);
}

char *get_help_txt(void)
{
    char *str = NULL;
    str = str_cat(str, "HELP\n");
    str = str_cat(str, "Shortcut :\nP : Pencil tool\nE : Eraser tool\n");
    str = str_cat(str, "Ctrl + n : Add layer\nCtrl + d : Delete layer\n");
    str = str_cat(str, "Ctrl + z : Undo\nCtrl + y : Redo\n");
    str = str_cat(str, "Ctrl + s : Save an image\n");
    str = str_cat(str, "M + click : Move on canvas\n");
    str = str_cat(str, "K : To zoom\n");
    str = str_cat(str, "L : To unzoom\n");
    str = str_cat(str, "Usage:\nMouse or shortcut to select tools,");
    str = str_cat(str, " and draw on the canvas\n");
    str = str_cat(str, "You can add a layer,");
    str = str_cat(str, " it protect you from undo past drawings\n");
    str = str_cat(str, "To save an image : use terminal to input filename\n");
    str = str_cat(str, "To open an image : use terminal to input filename\n");
    return (str);
}

void help_press_left(paint_t *info)
{
    add_ok_button(info);
    info->window_size = sfRenderWindow_getSize(info->window);
    button_info_t button_help = {0};
    button_help.color = BTN_LIGHT;
    button_help.font_size = 20;
    button_help.is_activ = false;
    button_help.pos = (sfVector2f){info->window_size.x / 2,
        info->window_size.y / 2};
    button_help.pressed_left = NULL;
    button_help.hover = NULL;
    button_help.size = (sfVector2f){600, 600};
    button_help.text = NULL;
    button_help.text = get_help_txt();
    priority_button_add(info->gui->prio, button_help);
    free(button_help.text);
}
