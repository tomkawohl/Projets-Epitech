/*
** EPITECH PROJECT, 2022
** include
** File description:
** src.h
*/

#ifndef SRC_H_
    #define SRC_H_
    #define WALL 'X'
    #define WAY '*'
    #define WALL_I -1
    #define U_INT unsigned int
    #define z_bool unsigned int
    #define true 1
    #define false 0
    #define RIGHT 0
    #define BOT 1
    #define LEFT 2
    #define TOP 3

    #include "../lib/tools/include/tools.h"
    #include "../lib/w_printf/include/w_printf.h"
    #include <stdlib.h>
    #include <time.h>

typedef struct stack_coord_s {
    int x;
    int y;
    struct stack_coord_s *prev;
    struct stack_coord_s *next;
} stack_coord_t;

typedef struct stack_s {
    stack_coord_t *first;
    stack_coord_t *end;
    unsigned int size;
} stack_t;

typedef struct coord_s {
    int x;
    int y;
} coord_t;

typedef struct cell_s {
    int x;
    int y;
    z_bool visited;
} cell_t;

/* give coord and nb_cell */
typedef struct merge_s {
    int x;
    int y;
    int nb_cell;
} merge_t;

typedef struct maze_data_s {
    int **maze;
    int **visit;
    int m_x;
    int m_y;
    long long int count;
} maze_data_t;

/*-------[BACK TRACKER]-------*/
int **bt_init_maze(int x, int y);
int **bt_init_visit(int x, int y);
void bt_generate_maze(maze_data_t *maze_data, stack_t *stack, int x, int y);
void bt_print_final_maze(maze_data_t *maze_data);
coord_t back_track(maze_data_t *maze_data, coord_t pos, stack_t *stack);
void print_stack(list_t *stack);
z_bool bt_is_stack_empty(int set, int get);
int get_dir(int set, int get);
z_bool bt_is_cell_valid(maze_data_t *maze_data, int x, int y);
z_bool verify_cell(maze_data_t *maze_data, int x, int y, int dir);
void bt_add_way(maze_data_t *maze_data, int *x, int *y, stack_t *stack);
void bt_updade_maze_if_pair(maze_data_t *maze_data);
void bt_make_maze_imperfect(maze_data_t *maze_data);

/*-------[STACK]-------*/
stack_t *stack_create(void);
void stack_add(stack_t *stack, int x, int y);
void stack_remove(stack_t *stack);
void stack_clear(stack_t *stack);
void stack_print(stack_t *stack);

/*-------[ELLER ALGOR]-------*/
void handle_eller_algo(int x);
int *set_first_row(int x);
int *set_second_row(int *row, int x);
int *set_unique_number(int *row, int x);
unsigned int get_serie_size(int *row, int i, int x);
void merge_horizontal(void);
void put_wall_first_row(int *first_row, int i, int *j, int *was_way);
void put_number_first_row(int *first_row, int i, int j, int *was_way);

/*-------[CHECK INPUT]-------*/
int check_inputs(int ac, char **av);
int check_ac(int ac);
int check_av(int ac, char **av);
int check_value_inputs(char **av);

/*-------[SETUP MAZE]-------*/
int **setup_maze(int x, int y);
void fill_line_wall(int **maze, int i, int x);
void fill_line_way_wall(int **maze, int i, int x);
int add_cell(void);

/*-------[GENERATE MAZE]-------*/
void generate_maze(maze_data_t *maze_data);
int is_maze_done(maze_data_t *maze_data);
coord_t pick_wall(maze_data_t *maze_data);
void break_wall(maze_data_t *maze_data, int x, int y);
//void merge_way(int **maze, int x, int ceil_1, int ceil_2);
void merge_way(maze_data_t *maze_data, int x, int y, int number);

/*-------[FINAL MAZE]-------*/
void print_final_maze_int(int **maze, int x, int y);
void int2d_to_str(int **tab, int x, int y);
int get_i_str(int *i);
void print_maze_x_impair(int **tab, int x, int y, int tab_size);
void print_last_line(int x);
void print_maze_x_pair(int **tab, int x, int y, int tab_size);

/*-------[RECURSIVE BACK TRACKER]-------*/
int **rbt_setup_maze(int x, int y);
void rbt_generate_maze(int **maze, int y, int x, coord_t limit);
void rbt_print_maze(int **maze, int x, int y);

/*-------[IS IMPAIR]-------*/
int is_y_impair(int set, int get);
int is_x_impair(int set, int get);

/*-------[MANAGE COORD]-------*/
void manage_coord(int *x, int *y);

/*-------[MAZE DATA]-------*/
maze_data_t *maze_data_init(int x, int y);
void maze_data_free(maze_data_t *maze_data);

/*-------[MAZE IMPERFECT]-------*/
void make_maze_imperfect(maze_data_t *maze_data);

/*-------[FLAG]-------*/
int flag_is_perfect(int set, int get);

#endif /* SRC_H_ */
