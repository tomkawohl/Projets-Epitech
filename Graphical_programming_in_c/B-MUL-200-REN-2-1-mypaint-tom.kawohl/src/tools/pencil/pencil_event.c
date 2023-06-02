/*
** EPITECH PROJECT, 2022
** tools/pencil
** File description:
** pencil_event
*/
#include "my_paint.h"

void pencil_add_vertex_square(pencil_t *pencil, int i)
{
    int x = 0;
    int y = 0;
    int index = 0;

    for (register int j = (-pencil->size); j <= pencil->size; j++) {
        x = (int)(pencil->pos.x + i);
        y = (int)(pencil->pos.y + j);
        if (x >= 0 && x < pencil->limit.x && y >= 0 && y < pencil->limit.y) {
            index = (y * pencil->limit.x + x) * 4;
            pencil->pixels[index + 0] = pencil->color.r;
            pencil->pixels[index + 1] = pencil->color.g;
            pencil->pixels[index + 2] = pencil->color.b;
            pencil->pixels[index + 3] = pencil->color.a;
        }
    }
}

void pencil_add_vertex(paint_t *info, sfEvent event, pencil_t *pencil,
    int *undo)
{
    if (*undo != 0)
            list_texture_remove_unactiv(pencil->current_layer->list_texture);
        (*undo) = 0;
        pencil->is_drawing = true;
        pencil->pos.x = event.mouseMove.x / info->window_zoom;
        pencil->pos.y = event.mouseMove.y / info->window_zoom;
        pencil->vertex.position.x = pencil->pos.x;
        pencil->vertex.position.y = pencil->pos.y;
        for (register int i = (-pencil->size); i <= pencil->size; i++) {
            if (pencil->form == SQUARE)
                pencil_add_vertex_square(pencil, i);
            else
                pencil_add_vertex_circle(pencil, i);
        }
}

void pencil_click_left(paint_t *info, sfEvent event, pencil_t *pencil,
    int *undo)
{
    if (event.type == sfEvtMouseMoved
    && sfMouse_isButtonPressed(sfMouseLeft) && get_is_in_perimiter(
        event.mouseMove.y / info->window_zoom,
        event.mouseMove.x / info->window_zoom,
        info->canvas->perim, pencil->size) == true && info->move == false) {
        pencil_add_vertex(info, event, pencil, undo);
    }
}

void reset_if_released_pencil(sfEvent event, int *can_undo, int *can_redo)
{
    if (event.type == sfEvtKeyReleased) {
        (*can_undo) = true;
        (*can_redo) = true;
    }
}

void pencil_event(paint_t *info, sfEvent event, pencil_t *pencil)
{
    static int undo = 0;
    static int can_undo = true;
    static int can_redo = false;
    static sfColor color = (sfColor){0, 0, 0, 255};

    if (pencil->is_activ == false && pencil->is_eraser == false)
        return;
    if (pencil->is_eraser == true)
        pencil->color = sfWhite;
    else
        pencil->color = color;
    if (has_layer_changed(false, true)) {
        undo = 0;
        has_layer_changed(false, false);
    }
    pencil_click_left(info, event, pencil, &undo);
    pencil_update_release(event, pencil);
    pencil_undo(pencil, &undo, &can_undo);
    pencil_redo(pencil, &undo, &can_redo);
    reset_if_released_pencil(event, &can_undo, &can_redo);
}
