/*
** EPITECH PROJECT, 2023
** open_window
** File description:
** open_window
*/

#include "src.h"
#include "parser.h"
#include "string.h"

static int malloc_struct(window_t *wd)
{
    wd->info = malloc(sizeof(data_t));
    if (wd->info == NULL)
        return 84;
    wd->line = malloc(sizeof(sfRectangleShape *) * (1920 / 48 + 1080 / 48 + 1));
    if (wd->line == NULL)
        return 84;
    return 0;
}

static data_t *init_data(data_t *info, info_t *tab, window_t *wd, char *count)
{
    char *str = "start";
    int room = 1;
    sfColor color = sfRed;
    sfVector2f pos;
    wd->count = malloc(sizeof(sfRectangleShape *) * (tab->nb_cells));
    wd->tile = malloc(sizeof(sfRectangleShape *) * (tab->nb_cells));
    wd->text = malloc(sizeof(sfText *) * (tab->nb_cells));
    for (size_t i = 0; i < tab->nb_cells; i++){
        if (i > 0) {
            count = "0";
            str = NULL;
            color = sfBlue;
            str = str_cat(str, "room\n");
            str = str_cat(str, int_to_string(room));
            room++;
        }
        wd->tile[i] = ssl_new_rect((sfVector2f){48, 48}, color,
        (sfVector2f){tab->room[i].x * 48, tab->room[i].y * 48});
        pos = sfRectangleShape_getPosition(wd->tile[i]);
        pos.x += 5;
        pos.y += 5;
        if (i + 1 == tab->nb_cells){
            str = "end";
            pos.x += 3;
        }
        wd->text[i] = ssl_new_text(sfFont_createFromFile("util/font.ttf"),
        (sfVector2f){0.5, 0.5}, pos, str);
        pos.x += 13;
        pos.y += 25;
        wd->count[i] = ssl_new_text(sfFont_createFromFile("util/font.ttf"),
        (sfVector2f){0.5, 0.5}, pos, count);
    }
    sfVideoMode mode = {1920, 1080, 32};
    info->window = sfRenderWindow_create(mode, "Bonus-Lemin", sfClose, NULL);
    return info;
}

static void detect_event(window_t *wd)
{
    while (sfRenderWindow_pollEvent(wd->info->window, &(wd->info->event))){
        wd->info->mouse = sfMouse_getPositionRenderWindow(wd->info->window);
        if (wd->info->event.type == sfEvtClosed) {
            sfRenderWindow_close(wd->info->window);
        }
    }
}

void open_window(info_t *info, graph_element_t *graph)
{
    char *count = int_to_string(info->nb_ants);
    window_t *wd = malloc(sizeof(window_t));
    if (wd == NULL)
        return;
    if (malloc_struct(wd) == 84)
        return;
    int i = 1;
    wd->info = init_data(wd->info, info, wd, count);
    int size = init_line(wd);
    sfClock *clock = sfClock_create();
    sfTime time;
    time.microseconds = 1000000;
    while (sfRenderWindow_isOpen(wd->info->window)){
        time = sfClock_getElapsedTime(clock);
        if (time.microseconds > 1000000){
            detect_event(wd);
            sfText_setString(wd->count[0], int_to_string(info->nb_ants));
            sfRenderWindow_clear(wd->info->window, sfBlack);
            draw_line(wd->line, size, wd, info);
            sfRenderWindow_display(wd->info->window);
            sfClock_restart(clock);
            if (info->nb_ants != 0){
                info->nb_ants--;
            }
        }
    }
}
