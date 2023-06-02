/*
** EPITECH PROJECT, 2022
** gui_info/
** File description:
** gui_info_draw
*/
#include "my_paint.h"

void display_down(button_t *button_down, paint_t *info)
{
    if (button_down->rect != NULL) {
        update_resize_rect(button_down->rect, button_down->hitbox,
            info);
        sfRenderWindow_drawRectangleShape(info->window,
            button_down->rect, NULL);
    }
    if (button_down->text != NULL) {
        update_resize_text(button_down->text, button_down->text_hitbox,
            info);
        sfRenderWindow_drawText(info->window, button_down->text, NULL);
    }
    return;
}

void gui_button_draw(button_main_t *button, paint_t *info)
{
    if (button->main_display == true) {
        if (button->main->rect != NULL) {
            update_resize_rect(button->main->rect, button->main->hitbox,
                info);
            sfRenderWindow_drawRectangleShape(info->window,
                button->main->rect, NULL);
        }
        if (button->main->text != NULL) {
            update_resize_text(button->main->text, button->main->text_hitbox,
                info);
            sfRenderWindow_drawText(info->window, button->main->text, NULL);
        }
    }
    if (button->down_display == true) {
        for (U_INT i = 0; button->down[i] != NULL; i++)
            display_down(button->down[i], info);
    }
    return;
}

void display_down_right(button_t *button_down, paint_t *info)
{
    if (button_down->rect != NULL) {
        update_resize_rect_right_middle(button_down->rect, button_down->hitbox,
            info);
        sfRenderWindow_drawRectangleShape(info->window,
            button_down->rect, NULL);
    }
    if (button_down->text != NULL) {
        update_resize_text_right_middle(button_down->text,
            button_down->text_hitbox, info);
        sfRenderWindow_drawText(info->window, button_down->text, NULL);
    }
    return;
}

void gui_button_draw_right(button_main_t *button, paint_t *info)
{
    if (button->main_display == true) {
        if (button->main->rect != NULL) {
            update_resize_rect_right_middle(button->main->rect,
                button->main->hitbox, info);
            sfRenderWindow_drawRectangleShape(info->window,
                button->main->rect, NULL);
        }
        if (button->main->text != NULL) {
            update_resize_text_right_middle(button->main->text,
                button->main->text_hitbox, info);
            sfRenderWindow_drawText(info->window, button->main->text, NULL);
        }
    }
    if (button->down_display == true) {
        for (U_INT i = 0; button->down[i] != NULL; i++)
            display_down_right(button->down[i], info);
    }
    return;
}

void rightbar_display(paint_t *info)
{
    update_resize_rect_right(info->gui->rightbar[0]->main->rect,
        info->gui->rightbar[0]->main->hitbox, info);
    sfRenderWindow_drawRectangleShape(info->window,
        info->gui->rightbar[0]->main->rect, NULL);
    if (info->gui->rightbar[1]->main_display == true) {
        gui_button_draw_right(info->gui->rightbar[1], info);
    } else if (info->gui->rightbar[2]->main_display == true) {
        gui_button_draw_right(info->gui->rightbar[2], info);
    }
    return;
}
