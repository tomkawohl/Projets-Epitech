/*
** EPITECH PROJECT, 2023
** draw_line
** File description:
** draw_line
*/

#include "src.h"
#include "parser.h"

int init_line(window_t *wd)
{
    int line = 1920 / 48 + 1080 / 48 + 1;
    sfVector2f size[] = {{1, 1080}, {1920, 1}};
    sfVector2f pos = {0, 0};
    int index = 0;

    for (int i = 0; i < line ; i++){
        wd->line[i] = ssl_new_rect(size[index], sfColor_fromRGB(80, 80, 80), pos);
        if (pos.x < 1920 && pos.y == 0)
            pos.x += 48;
        else {
            pos.x = 0;
            pos.y += 48;
            index = 1;
        }
    }
    return line;
}

void draw_line(sfRectangleShape **line, int size, window_t *wd, info_t *info)
{
    static int index = 0;
    int check = 0;
    for (int i = 0; i < size; i++){
        sfRenderWindow_drawRectangleShape(wd->info->window, line[i], NULL);
    }
    for (size_t i = 0; i < info->nb_cells; i++){
        if (info->way[index] == (int)i && check == 0){
            sfRectangleShape_setFillColor(wd->tile[i], sfRed);
            check++;
            index++;
        }
        sfRenderWindow_drawRectangleShape(wd->info->window, wd->tile[i], NULL);
        sfRenderWindow_drawText(wd->info->window, wd->text[i], NULL);
        sfRenderWindow_drawText(wd->info->window, wd->count[i], NULL);
    }
}
