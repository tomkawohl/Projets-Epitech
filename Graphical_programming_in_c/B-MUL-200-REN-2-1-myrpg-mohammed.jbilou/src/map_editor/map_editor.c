/*
** EPITECH PROJECT, 2023
** map_editor
** File description:
** map_editor
*/
/**
 * @file map_editor.c
 *
 * @brief Handle map editor
 *
 * @date 06/04/2023
*/
#include "src.h"
#include "lib_will.h"
#include "text_list.h"

static bool init_pop_index(game_t *gm, map_edit_t *map_edit)
{
    for (size_t i = 0; i < NB_WINDOWS; i++)
        gm->m_wd[i].index = i;
    return true;
}

static bool check_file(char *filepath)
{
    struct stat info;

    if (filepath == NULL)
        return false;
    if (stat(filepath, &info) < 0)
        return false;
    return true;
}

static void init_map_editor(sfRenderWindow *win, game_t *gm,
                            map_edit_t *map_edit, char *input)
{
    while (sfRenderWindow_isOpen(win)) {
        map_edit->file_to_open = NULL;
        map_editor_handle_event(gm, map_edit);
        map_editor_handle_screen(win, map_edit);
        if (map_edit->file_to_open != NULL
        && map_edit->file_to_open[0] != '\0'
        && check_file(map_edit->file_to_open)) {
            map_edit->tiles_pos_set = tile_pos_set_update(
                map_edit->tiles_pos_set, map_edit->file_to_open,
                map_edit->grid->limit, map_edit);
            open_destroy_ressources(map_edit);
            map_edit->grid = file_to_map(map_edit->file_to_open, true);
            map_edit->units = file_to_map_unit(map_edit->file_to_open);
            update_map_edit_open(map_edit, map_edit->file_to_open);
            map_edit->file_to_open = NULL;
        }
        if (map_edit->state == EXIT)
            break;
    }
}

void map_editor(sfRenderWindow* win, game_t *gm)
{
    sfEvent event;
    map_edit_t *map_edit = map_editor_init();
    char *input = NULL;
    if (!verify_malloc(map_edit, "map_editor"))
        return;
    init_pop_index(gm, map_edit);
    init_map_editor(win, gm, map_edit, input);
    map_edit_destroy(map_edit);
}

/*
features :
 - H to hide set
 - A to add tile
 - E to delete tile
 - C to put colision
 - Ctrl + s (press 2 times s to make it work) to save a map
 - Ctrl + o (press 2 times o to make it work) to open a map
 - Ctrl + n (press 2 times n to make it work) to create a new grid
 - arrow to change set
 - Z Q S D to move on canva
 - Escape to exit
 - Escape to exit
*/
