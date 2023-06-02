/*
** EPITECH PROJECT, 2022
** manage_sprites
** File description:
** manage_sprites
*/
#include "my_all.h"
#include "my_printf.h"
#include "src.h"


sfIntRect set_sprite(sfSprite *sprite, int widgth, int height)
{
    sfIntRect rect;
    rect.top = 0;
    rect.left = 0;
    rect.width = widgth;
    rect.height = height;
    sfSprite_setTextureRect(sprite, rect);
    return (rect);
}

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    if (rect->left + offset >= max_value) {
        rect->left = 0;
    } else {
        rect->left += offset;
    }
}

void create_sprite(object_t *obj, char const *path, sfVector2f size)
{
    obj->texture = sfTexture_createFromFile(path, NULL);
    obj->sprite = sfSprite_create();
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    sfSprite_setScale(obj->sprite, size);
}

void animate_sprite(object_t *obj, g_time_t *t, int offset, int max_value)
{
    t->time = sfClock_getElapsedTime(t->clock);
        t->seconds = t->time.microseconds / 1000000.0;
        if (t->seconds > obj->anim) {
            move_rect(&(obj->rect), offset, max_value);
            sfClock_restart(t->clock);
        }
        sfSprite_setTextureRect(obj->sprite, obj->rect);
}
