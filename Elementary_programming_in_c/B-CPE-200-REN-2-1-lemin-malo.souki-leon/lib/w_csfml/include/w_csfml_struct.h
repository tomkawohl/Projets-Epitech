/*
** EPITECH PROJECT, 2022
** include
** File description:
** w_csfml_struct.h
*/

#ifndef W_CSFML_STRUCT_H_
    #define W_CSFML_STRUCT_H_
    #include <SFML/Graphics.h>

/* anim_speed in deca_second and init anim to TRUE or 1 */
typedef struct object_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfIntRect hitbox;
    sfRectangleShape *hitbox_r;
    sfCircleShape *hitbox_c;
    float speed;
    sfVector2f dep;
    sfVector2f arr;
    int delay;
    int is_crashed;
    int has_landed;
    int has_took_off;
    float radius;
    double angle;
    sfVector2f direction;
} object_t;

typedef struct w_clock_s {
    int hour;
    int minute;
    int second;
    int microsecond;
    sfClock *clock;
} w_clock_t;

typedef struct obj_hitbox_s {
    sfVector2f get_pos;
    sfIntRect get_hitbox;
} obj_hitbox_t;

typedef struct matrix_s {
    float a;
    float b;
    float c;
    float d;
    float e;
    float f;
    float g;
    float h;
    float i;
} matrix_t;

#endif /* W_CSFML_STRUCT_H_ */
