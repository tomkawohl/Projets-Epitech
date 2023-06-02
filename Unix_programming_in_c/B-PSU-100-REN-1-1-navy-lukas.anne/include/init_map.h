/*
** EPITECH PROJECT, 2022
** src
** File description:
** init_map.h
*/

#ifndef INIT_MAP_H_
    #define INIT_MAP_H_
    #include "../lib/tools/include/tools.h"
    #include "../lib/w_printf/include/w_printf.h"
    #include <stdlib.h>
    #include <signal.h>
    #include <stddef.h>
    #include <unistd.h>
    #include <sys/types.h>

/* init_map */
char **map_init(char *arg);

/* map_struct_init */
map_t *map_struct_init(void);

/* is_file_valid */
int is_file_valid(char *file);

/* abs */
int int_abs(int n);

/* game_tools */
/* take the letter and give the index for the tab */
int letter_into_int(char c);

/* check if the line is horizontal or not */
int is_horizontal(char **map_info_2d, int i);

/* check if the boat go to the left or not */
int to_left(char **map_info_2d, int i);

/* check if the boat go to the down or not */
int to_down(char **map_info_2d, int i);

/* init_horizontal */
void init_horizontal(char **map, char **map_info_2d, int i, int j);

/* init_vertical */
void init_vertical(char **map, char **map_info_2d, int i, int j);

int check_map_info(char **map_info_2d);

int init_collisions(char *boat_pos, char **map_info_2d, int i);
void fill_boat_pos_horizontal(char **boat_pos, char **map_info_2d, int i);
void fill_boat_pos_vertical(char **boat_pos, char **map_info_2d, int i);

#endif /* INIT_MAP_H_ */
