##
## EPITECH PROJECT, 2022
## setup
## File description:
## Makefile
##

TEST_N	=	unit_tests

GRAPH = src/graph

PARSER_FILE = src/parser/file

PARSER_PARSE = src/parser/parsing

ERRORS = src/errors

PROGRAM = src/program

DEBUG	=	src/debug

HANDLE_ANTS	=	src/handle_ants

HANDLE_LEM_IN = src/handle_lem_in

SRC	=	src/main.c	\
		\
		$(GRAPH)/graph_create.c			\
		$(GRAPH)/graph_destroy.c		\
		$(GRAPH)/graph_print.c			\
		$(GRAPH)/graph_init.c			\
		$(GRAPH)/graph_has_solution.c	\
		\
		$(GRAPH)/node/node_add.c		\
		$(GRAPH)/node/node_remove.c		\
		$(GRAPH)/node/node_print.c		\
		$(GRAPH)/node/node_add_name.c	\
		\
		$(GRAPH)/edge/edge_add.c	\
		\
		$(GRAPH)/weight/weight_update.c			\
		$(GRAPH)/weight/weight_add.c			\
		$(GRAPH)/weight/weight_vertice_to_end.c	\
		$(GRAPH)/weight/weight_set.c			\
		\
		$(PARSER_FILE)/file_to_buffer.c	\
		\
		$(PARSER_PARSE)/get_info_from_buffer.c	\
		$(PARSER_PARSE)/rooms_to_structure.c	\
		$(PARSER_PARSE)/info_to_struct_tab.c	\
		$(PARSER_PARSE)/get_links_from_cells.c	\
		$(PARSER_PARSE)/check_positions.c	\
		\
		$(ERRORS)/check_malloc.c	\
		$(ERRORS)/check_file.c	\
		\
		$(PROGRAM)/destroy_program.c	\
		\
		$(HANDLE_ANTS)/ant_move.c	\
		\
		$(HANDLE_LEM_IN)/handle_lem_in.c	\
		$(HANDLE_LEM_IN)/ants_move_all.c	\
		$(HANDLE_LEM_IN)/print_file.c	\
		\
		$(DEBUG)/show_rooms.c
		\

SRC += src/window/open_window.c
SRC += src/window/draw_line.c

SFML	=	-lcsfml-system -lcsfml-window -lcsfml-audio -lcsfml-graphics

TESTS	=	$(ERRORS)/check_malloc.c	\
			tests/lemin_tests.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -I include/ -I lib/ssl/includes/ -I lib/ssl/includes/ssl/

LDFLAGS	=	-L./lib/ -l:libw_printf.a
LDFLAGS +=  -L./lib/ -l:libtools.a
LDFLAGS += -L./lib/ -l:libmsl.a

NAME	=	lem_in

all:	$(NAME)

$(NAME):	make_lib $(OBJ)
	@ gcc -o $(NAME) $(OBJ) $(LDFLAGS) $(SFML)

.c.o:
	@ gcc $(CFLAGS) -c $< -o $@
	@ echo "$< -> $@"

make_lib:
	@ $(MAKE) -sC lib/tools/
	@ $(MAKE) -sC lib/w_printf/

clean:
	@ $(RM) *~
	@ $(RM) *gcda
	@ $(RM) *gcno
	@ $(RM) *.log
	@ $(RM) $(TEST_N)
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

unit_tests: re
	gcc $(TESTS) $(CFLAGS) -L . $(LDFLAGS) -lcriterion -o $(TEST_N) --coverage

tests_run: unit_tests
	./$(TEST_N)

.PHONY: all make_lib clean fclean debug see_debug re
