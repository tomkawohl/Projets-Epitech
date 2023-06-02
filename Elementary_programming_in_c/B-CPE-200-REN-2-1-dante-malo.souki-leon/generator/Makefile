##
## EPITECH PROJECT, 2022
## setup
## File description:
## Makefile
##
SRC	=	src/main.c \
		\
		src/back_tracker/bt_init_maze.c				\
		src/back_tracker/bt_init_visit.c			\
		src/back_tracker/bt_generate_maze.c			\
		src/back_tracker/bt_print_final_maze.c		\
		src/back_tracker/bt_has_dir_way.c			\
		src/back_tracker/bt_is_stack_empty.c		\
		src/back_tracker/bt_is_cell_valid.c			\
		src/back_tracker/bt_add_way.c				\
		src/back_tracker/bt_update_maze_if_pair.c	\
		src/back_tracker/bt_make_maze_imperfect.c	\
		\
		src/back_tracker/debug/print_stack.c	\
		\
		src/back_tracker/stack/stack_create.c	\
		src/back_tracker/stack/stack_add.c		\
		src/back_tracker/stack/stack_remove.c	\
		src/back_tracker/stack/stack_clear.c	\
		src/back_tracker/stack/stack_print.c	\
		\
		src/check_inputs/check_inputs.c			\
		src/check_inputs/check_ac.c				\
		src/check_inputs/check_av.c				\
		src/check_inputs/check_values_inputs.c	\
		\
		src/kruskal_algo/setup_maze/setup_maze.c			\
		src/kruskal_algo/setup_maze/fill_line_wall.c		\
		src/kruskal_algo/setup_maze/fill_line_way_wall.c	\
		src/kruskal_algo/setup_maze/add_cell.c				\
		\
		src/kruskal_algo/generate_maze/generate_maze.c	\
		src/kruskal_algo/generate_maze/is_maze_done.c	\
		src/kruskal_algo/generate_maze/pick_wall.c		\
		src/kruskal_algo/generate_maze/break_wall.c		\
		src/kruskal_algo/generate_maze/merge_way.c		\
		\
		src/final_maze/print_final_maze_int.c	\
		src/final_maze/int2d_to_str.c			\
		src/final_maze/print_maze_x_impair.c	\
		src/final_maze/get_i_str.c				\
		src/final_maze/print_maze_x_pair.c		\
		\
		src/recursive_back_tracker/rbt_setup_maze.c		\
		src/recursive_back_tracker/rbt_generate_maze.c	\
		src/recursive_back_tracker/rbt_print_maze.c		\
		\
		src/kruskal_algo/is_impair/is_y_impair.c	\
		src/kruskal_algo/is_impair/is_x_impair.c	\
		\
		src/kruskal_algo/manage_coord/manage_coord.c	\
		\
		src/kruskal_algo/maze_data/maze_data_init.c	\
		src/kruskal_algo/maze_data/maze_data_free.c	\
		\
		src/maze_imperfect/make_maze_imperfect.c	\
		\
		src/flag/flag_is_perfect.c	\
		\
		src/eller_algo/handle_eller_algo.c	\
		src/eller_algo/set_first_row.c		\
		src/eller_algo/set_second_row.c		\
		src/eller_algo/get_serie_size.c		\
		src/eller_algo/set_unique_number.c	\
		src/eller_algo/merge_horizontal.c	\
		\
		src/eller_algo/set_rows/put_rows.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -I include/

LDFLAGS	=	-L./lib/
LDFLAGS += -l:libw_printf.a -L./lib/ -l:libtools.a

NAME	=	generator

all:	$(NAME)

$(NAME):	make_lib $(OBJ)
	@ gcc -o $(NAME) $(OBJ) $(LDFLAGS) -lm

.c.o:
	@ gcc $(CFLAGS) -c $< -o $@
	@ echo "$< -> $@"

make_lib:
	@ $(MAKE) -sC lib/tools/
	@ $(MAKE) -sC lib/w_printf/

clean:
	@ $(RM) *~
	@ $(RM) $(OBJ) $(addsuffix ~, $(SRC))

fclean : clean
	@ $(RM) $(NAME)
	@ make fclean -sC lib/tools/
	@ make fclean -sC lib/w_printf/

debug: CFLAGS += -g -pg
debug: LDFLAGS += -pg
debug: fclean all

see_debug: gprof ./$(NAME) ./gmon.out \
rm gmon.out

re:	fclean all

.PHONY: all make_lib clean fclean debug see_debug re
