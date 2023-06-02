/*
** EPITECH PROJECT, 2022
** src
** File description:
** src.h
*/

#ifndef SRC_H_
    #define SRC_H_
    #include "../lib/tools/include/tools.h"
    #include "../lib/w_printf/include/w_printf.h"
    #include "../lib/w_csfml/include/w_csfml.h"

/* struct for events */

typedef struct w_event_s {
    sfEvent event;
    int display_hitbox;
    int display_sprite;
} w_event_t;

typedef struct text_s {
    sfFont *font;
    sfText *text;
} text_t;
char **parse_file(const char *file);
int radar(char **map_info);

/* count_element */
int count_airplane(char **map_info);
int count_tower(char **map_info);

/* init_element */
void init_planes(char **map_info, object_t **planes, int nb_plane);
void init_towers(char **map_info, object_t **towers, int nb_tower);

/* init direction */
void init_direction(object_t **planes, int i,
                    sfVector2f origin, sfVector2f dest);

/* destroy element */
void obj_destroy_all(object_t **obj);

/*simulation */
void simulation(object_t **airplanes, object_t **towers);

/* planes_display */
int planes_display(sfRenderWindow *win, object_t **planes, w_event_t w_event);

/* tower_display */
void towers_displays(sfRenderWindow *win, object_t **towers, w_event_t w_event);

/* planes_move */
void planes_move(object_t **planes, w_clock_t *w_clock);

/* events */
w_event_t init_w_event(void);
void handle_events(sfRenderWindow *win, w_event_t *w_event);

/* collision */
int detect_collision_r(object_t *obj_1, object_t *obj_2);
void collision(object_t **planes, object_t **towers);

/* text */
text_t text_create(void);
void text_destroy(text_t *text);
void draw_text(sfRenderWindow *win, text_t timer, w_clock_t *w_clock);

/* description */
void description(const char *filename);

/* angle */
void calcul_angle(object_t **planes, int i);

/* error */
void msg_wrong_file(void);

/* matrix */
matrix_t matrix_rotation(float angle);
sfVector2f transform_points(sfVector2f points, matrix_t rot);

/* debug */
void debug(void);
void debug_init_planes(object_t **planes, int nb_planes);
void debug_init_towers(object_t **towers);
void debug_simulation(object_t **planes, object_t **towers);
void debug_event(sfRenderWindow *win, sfEvent *event,object_t **planes);
void debug_display(sfRenderWindow *win, object_t **planes, object_t **towers);
void debug_obj_rotate(object_t *obj);

#endif /* SRC_H_ */
