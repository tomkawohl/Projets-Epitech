/*
** EPITECH PROJECT, 2022
** gui_info/
** File description:
** gui_info_init
*/
#include "my_paint.h"

button_main_t *init_button_main(sfVector2f pos, sfVector2f size,
    sfColor color)
{
    button_main_t *button = malloc(sizeof(*button));
    button->main = button_init(pos, size, color);
    button->main_activ = true;
    button->main_display = true;
    button->down_activ = false;
    button->down_display = false;
    button->down = NULL;
    return (button);
}

void gui_info_init_topbar(gui_info_t* gui, U_INT nb_button)
{
    sfVector2f pos = {0, 0};
    for (U_INT i = 1; i < nb_button; i++) {
        gui->topbar[i] = init_button_main(pos,
            (sfVector2f){100.0, TOPBAR_HEIGHT_BTN}, TOP_BG);
        pos.x += 100.0;
    }
    button_set_text(gui->topbar[1]->main, "File", FONT_SIZE, FONT_BASIC);
    button_set_text(gui->topbar[2]->main, "Edit", FONT_SIZE, FONT_BASIC);
    button_set_text(gui->topbar[3]->main, "Help", FONT_SIZE, FONT_BASIC);
    gui->topbar[FILE]->down = file_btn_init();
    gui->topbar[EDIT]->down = edit_btn_init();
    gui->topbar[HELP]->down = help_btn_init();
}

gui_info_t *gui_info_init(void)
{
    gui_info_t *gui = malloc(sizeof(*gui));
    U_INT nb_button = 4;
    if (gui == NULL)
        return (NULL);
    gui->prio = priority_button_init();
    gui->topbar = malloc(sizeof(button_main_t *) * (nb_button + 1));
    gui->topbar[nb_button] = NULL;
    gui->topbar_activ = true;
    gui->topbar_display = true;
    gui->topbar[0] = init_button_main((sfVector2f){300, 0.0},
        (sfVector2f){WIDTH + 1500.0, TOPBAR_HEIGHT_BTN}, TOP_BG);
    gui->topbar[0]->main_activ = false;
    gui_info_init_topbar(gui, nb_button);
    gui->rightbar = rightbar_init();
    gui->rightbar_activ = false;
    gui->rightbar_display = false;
    return (gui);
}
