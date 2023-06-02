/*
** EPITECH PROJECT, 2022
** src.h
** File description:
** src.h
*/

#include <curses.h>
#include "struct.h"
#ifndef SRC_H_
    #define SRC_H_
    #define WALL '#'
    #define BOXE 'X'
    #define PLAYER 'P'
    #define LOC 'O'
    #define GROUND ' '

struct play_s {
    int key;
    void (*ptr_f)(char **game);
};
typedef struct play_s play_t;

/* get_size */
int get_colone_size(char *str, int i);
int get_line_size(char *str);
int get_colone_max(char *str);

/* get_position */
p_pos_t get_player(char **tab);

/* move */
void move_down(char **tab);
void move_up(char **tab) ;
void move_left(char **tab);
void move_right(char **tab) ;

/* can move */
int can_move_left(char **tab, p_pos_t pos);
int can_move_right(char **tab, p_pos_t pos);
int can_move_up(char **tab, p_pos_t pos);
int can_move_down(char **tab, p_pos_t pos);

/* move cube */
void move_boxe_left(char **tab, p_pos_t pos);
void move_boxe_right(char **tab, p_pos_t pos);
void move_boxe_up(char **tab, p_pos_t pos);
void move_boxe_down(char **tab, p_pos_t pos);

/* get loc */
int get_many_loc(char **tab);
l_pos_t *get_coord_loc(char **tab, int loc);
void check_coord_loc(char **tab, l_pos_t *coord_loc);

/* is_loc */
void is_loc(char **tab, int i, int j, int *loc);

/* get boxe */
int get_many_boxe(char **tab);
p_pos_t *get_coord_boxe(char **tab, int boxe);

/* game */
int game_loop(char *buffer, char **tab2d, l_pos_t *coord_loc);
int print_tab2d(char **tab2d, char *str, int colone_max);

/* check_win */
int check_win(char **tab, l_pos_t *coord_loc);

/* check_ lose */
int check_lose(char **tab, p_pos_t *coord_boxe);

/* handling_errors */
int is_char_valid(char c);
int handling_errors(char *str, char **tab);

/* other functions not sorted */
int free_tab2d(char **, char*);
int stat_file(char *);
char *handle_file(char *, int);
char **tab1d_to_2d(char *);
#endif /* SRC_H_ */
