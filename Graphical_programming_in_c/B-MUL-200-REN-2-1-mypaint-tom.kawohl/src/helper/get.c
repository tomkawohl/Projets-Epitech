/*
** EPITECH PROJECT, 2023
** src/gui/gui_top_init
** File description:
** get functions
*/

#include "my_paint.h"

float get_scale(float ori, float new_window, float window)
{
    float perc = ori / window;

    if (perc == 0.0)
        return (0.0);
    return ori / (new_window * perc);
}

my_bool get_is_in_perimiter(int y, int x, perimiter_t *perim, int size)
{
    size /= 2;
    if (y > perim->top + size && y < perim->top + perim->height - size &&
        x > perim->left + size && x < perim->left + perim->width - size)
        return true;
    return false;
}

int get_arrlen(char **arr)
{
    int i = 0;

    for (; arr[i] != NULL; i++);
    return i;
}

sfVector2f get_origin(paint_t *info)
{
    if (info->origin_status == RESIZE) {
        return ((sfVector2f) {0.0f, 0.0f});
    }
    if (info->origin_status == ZOOM) {
        return ((sfVector2f) {(float) sfMouse_getPositionRenderWindow(
            info->window).x / get_scale(WIDTH, sfMouse_getPositionRenderWindow(
            info->window).x, WIDTH) - info->canvas->perim->left,
                (float)sfMouse_getPositionRenderWindow(
            info->window).y / get_scale(HEIGHT,
                sfMouse_getPositionRenderWindow(
            info->window).y, WIDTH) - info->canvas->perim->top} );
    }
    return ((sfVector2f){0.0f, 0.0f});
}

my_bool get_input(paint_t *info)
{
    char *input = malloc(sizeof(char) * 1000);
    char **arr;
    char *extension;
    int len;

    my_printf("Input filename here: ");
    len = read(1, input, 1000);
    input[len - 1] = '\0';
    if (my_strlen(input) == 0)
        return false;
    arr = my_strtok(input, '.');
    extension = arr[get_arrlen(arr) - 1];
    if (my_strcmp(extension, "jpg") != 0 && my_strcmp(extension, "bmp") != 0 &&
        my_strcmp(extension, "png") != 0) {
        my_printf("We only support the following file formats:\n");
        my_printf("bmp, jpg, png\n");
        return false;
    }
    info->save.filename = input;
    return true;
}
