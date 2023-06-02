/*
** EPITECH PROJECT, 2022
** object
** File description:
** object
*/
#include "my_all.h"
#include "my_printf.h"
#include "src.h"

void destroy_object(object_t *obj)
{
    sfTexture_destroy(obj->texture);
    sfSprite_destroy(obj->sprite);
}
