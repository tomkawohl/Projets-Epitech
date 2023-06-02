/*
** EPITECH PROJECT, 2023
** map_editor
** File description:
** event/update_tools_selection.c
*/
/**
 * @file update_tools_selection.c
 *
 * @brief Update tools selection
 *
 * @date 07/04/2023
*/
#include "src.h"
#include "lib_will.h"

static void replace_mode(map_edit_t *map_edit, char *text)
{
    if (!text)
        return;
    text_list_remove(map_edit->list_text);
    text_list_add(map_edit->list_text, (text_info_t){NULL,
    (sfVector2i){32, 1}, text, 21, GUI_ASSET, (sfIntRect)TEXT_SQUARE, T_DEF});
    return;
}

void map_edit_change_state(map_edit_t *map_edit, int state)
{
    if (state == ADD) {
        map_edit->state = ADD;
        replace_mode(map_edit, "  Mode : Add \n  ");
    }
    if (state == COLLISION) {
        map_edit->state = COLLISION;
        replace_mode(map_edit, " Mode : Collision \n ");
    }
    if (state == DELETE) {
        map_edit->state = DELETE;
        replace_mode(map_edit, " Mode : Delete \n ");
    }
}

static int update_mode_selection(map_edit_t *map_edit, sfEvent event,
    bool *can_press)
{
    if (sfKeyboard_isKeyPressed(sfKeyA) && can_press) {
        map_edit->state = ADD;
        replace_mode(map_edit, "  Mode : Add \n  ");
        return (1);
    }
    if (sfKeyboard_isKeyPressed(sfKeyC) && can_press) {
        map_edit->state = COLLISION;
        replace_mode(map_edit, " Mode : Collision \n ");
        return (1);
    }
    if (sfKeyboard_isKeyPressed(sfKeyE) && can_press) {
        map_edit->state = DELETE;
        replace_mode(map_edit, " Mode : Delete \n ");
        return (1);
    }
    return (0);
}

void update_tools_selection(map_edit_t *map_edit, sfEvent event,
    bool *can_press)
{
    if (update_mode_selection(map_edit, event, can_press))
        return;
    if (sfKeyboard_isKeyPressed(sfKeyEscape) && can_press) {
        if (map_editor_exit()) {
            map_edit->state = EXIT;
            return;
        }
    }
    if (sfKeyboard_isKeyPressed(sfKeyF) && can_press) {
            map_edit->state = UNIT;
            replace_mode(map_edit, " Mode : Foreground \n ");
            return;
    }
    if (sfKeyboard_isKeyPressed(sfKeyR) && can_press) {
            map_edit->state = UNIT_DELETE;
            replace_mode(map_edit, " Mode : Foreground Remove \n ");
            return;
    }
    return;
}
