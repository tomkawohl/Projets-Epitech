/*
** EPITECH PROJECT, 2023
** open_file
** File description:
** open_file
*/
#include "my_paint.h"

char *get_input_open(void)
{
    char *input = malloc(sizeof(char) * 100);
    char **arr;
    char * extension;
    my_printf("Enter file name\n");
    read(1, input, 100);
    if (my_strlen(input) == 0)
        return (NULL);
    input[my_strlen(input) - 1] = '\0';
    arr = my_strtok(input, '.');
    extension = arr[get_arrlen(arr) - 1];
    if (my_strcmp(extension, "jpg") != 0 && my_strcmp(extension, "bmp") != 0 &&
        my_strcmp(extension, "png") != 0) {
        my_printf("We only support the following file formats:\n");
        my_printf("bmp, jpg, png\n");
        return (NULL);
    }
    return (input);
}

void open_file(paint_t *info)
{
    char *filename = get_input_open();
    sfImage *image;
    if (filename == NULL)
        return;
    image = sfImage_createFromFile(filename);
    layer_add(info->layer, WIDTH, HEIGHT);
    info->tools->pencil->current_layer = info->layer->first;
    sfTexture_destroy(info->layer->first->list_texture->first->texture);
    info->layer->first->list_texture->first->texture =
        sfTexture_createFromImage(image, NULL);
    sfSprite_setTexture(info->layer->first->list_texture->first->sprite,
    info->layer->first->list_texture->first->texture, sfTrue);
    sfSprite_setPosition(info->layer->first->list_texture->first->sprite,
    (sfVector2f){CANVAS_START_X, CANVAS_START_Y});
    free(filename);
    sfImage_destroy(image);
}
