/*
** EPITECH PROJECT, 2022
** gui_info/
** File description:
** gui_info_rightbar_init
*/
#include "my_paint.h"

void set_settings(button_main_t **rightbar)
{
    rightbar[1] = init_button_main(
        (sfVector2f){WIDTH - RIGHT_WIDTH, TOPBAR_HEIGHT_BTN},
            (sfVector2f){RIGHT_WIDTH,TOPBAR_HEIGHT_BTN},
        BTN_LIGHT);
    button_set_text(rightbar[1]->main, "Pencil Settings", FONT_SIZE,
        FONT_BASIC);
    rightbar[2] = init_button_main(
        (sfVector2f){WIDTH - RIGHT_WIDTH, TOPBAR_HEIGHT_BTN},
            (sfVector2f){RIGHT_WIDTH,TOPBAR_HEIGHT_BTN},
        BTN_LIGHT);
    button_set_text(rightbar[2]->main, "Eraser Settings", FONT_SIZE,
        FONT_BASIC);
    rightbar[1]->main_activ = false;
    rightbar[1]->main_display = false;
    rightbar[1]->down = init_pencil_setting();
    rightbar[2]->main_activ = false;
    rightbar[2]->down = init_eraser_setting();
    rightbar[2]->main_display = false;
}

button_main_t **rightbar_init(void)
{
    U_INT nb_button = 3;
    button_main_t **rightbar = malloc(sizeof(button_main_t *) *
        (nb_button + 1));
    rightbar[0] = init_button_main(
        (sfVector2f){WIDTH - RIGHT_WIDTH, TOPBAR_HEIGHT_BTN},
            (sfVector2f){RIGHT_WIDTH, HEIGHT - TOPBAR_HEIGHT_BTN},
        SETTING_CLR);
    rightbar[0]->main_activ = false;
    rightbar[0]->main_display = false;
    set_settings(rightbar);
    rightbar[nb_button] = NULL;
    return (rightbar);
}
