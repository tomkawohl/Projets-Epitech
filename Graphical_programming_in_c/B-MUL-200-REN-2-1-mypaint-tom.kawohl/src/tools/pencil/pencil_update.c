/*
** EPITECH PROJECT, 2022
** tools/pencil
** File description:
** pencil_update
*/
#include "my_paint.h"

void pencil_update_release(sfEvent event, pencil_t *pencil)
{
    if (event.type == sfEvtMouseButtonReleased && pencil->is_drawing == true) {
        pencil->is_drawing = false;
        list_texture_add(pencil->current_layer->list_texture, WIDTH, HEIGHT);
        memset(pencil->pixels, 0, sizeof(sfUint8) * WIDTH * HEIGHT * 4);
    }
}

void pencil_undo(pencil_t *pencil, int *undo, int *can_undo)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ)
    && sfKeyboard_isKeyPressed(sfKeyLControl) && (*can_undo) == true) {
        if ((U_INT)(*undo) < (pencil->current_layer->list_texture->size - 1)) {
            (*undo)++;
            list_texture_set_activ(
                pencil->current_layer->list_texture, false, (*undo));
            (*can_undo) = false;
        }
    }
}

void pencil_redo(pencil_t *pencil, int *undo, int *can_redo)
{
    if (sfKeyboard_isKeyPressed(sfKeyY)
    && sfKeyboard_isKeyPressed(sfKeyLControl) && (*can_redo) == true) {
        if ((*undo) > 0) {
            list_texture_set_activ(pencil->current_layer->list_texture,
                                    true, (*undo));
            (*undo)--;
            (*can_redo) = false;
        }
    }
}
