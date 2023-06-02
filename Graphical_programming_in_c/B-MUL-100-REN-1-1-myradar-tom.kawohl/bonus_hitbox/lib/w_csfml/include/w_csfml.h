/*
** EPITECH PROJECT, 2022
** include
** File description:
** w_csfml
*/

#ifndef W_CSFML_H_
    #define W_CSFML_H_
    #include "../../tools/include/tools.h"
    #include "w_csfml_struct.h"
    #include <stdlib.h>
    #include <math.h>
    #define UINT unsigned int

/* window */
sfRenderWindow *init_window(UINT width, UINT height, UINT bpp);

/* obj */
object_t *obj_sprite_create(const char *filename);
void obj_destroy(object_t *obj);

/* anim */
void obj_set_rect(object_t *obj, sfIntRect set_rect);
void obj_move_rect_right(object_t *obj, int offset, int max_value);
void obj_anim(object_t *obj, w_clock_t *w_clock, int offset, int max_value);

/* hitbox */
obj_hitbox_t obj_get_hitbox(object_t *obj);
sfRectangleShape *hitbox_rect(obj_hitbox_t obj_hitbox);
sfCircleShape *hitbox_circle(object_t *obj, float radius);

/* collision */
int detect_collision_circle(object_t *obj1, object_t *obj2);
int detect_collision_c_r(object_t *obj_c, object_t *obj_r);

/* move */
void obj_move(object_t *obj, sfVector2f move);
void obj_move_to(object_t *obj, w_clock_t *w_clock,
                sfVector2f origin, sfVector2f dest);

/* w_clock */
w_clock_t *w_clock_init(void);
void w_clock_update(w_clock_t *w_clock);

#endif /* W_CSFML_H_ */
