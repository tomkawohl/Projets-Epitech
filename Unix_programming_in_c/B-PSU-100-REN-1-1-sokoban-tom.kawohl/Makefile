##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##
SRC	=	src/main.c	\
		src/free_tab2d.c	\
		src/handle_file.c	\
		src/get_size.c	\
		src/tab1d_to_tab2d.c	\
		src/print_tab2d.c	\
		src/game_loop.c	\
		src/move.c	\
		src/get_position.c	\
		src/move_boxes.c	\
		src/can_move.c	\
		src/get_loc.c	\
		src/check_win.c	\
		src/get_boxe.c	\
		src/handling_errors.c	\
		src/is_loc.c	\
		src/check_lose.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban

CFLAGS	=	-Wall -Wextra

all:	$(NAME)

$(NAME):	copy_lib $(OBJ)
	gcc -o my_sokoban $(OBJ) -L./lib/ -lmy -L./lib/ -lmy_all -lncurses
copy_lib:
	cp src/src.h include/
	cp src/struct.h include/
	make -C lib/my/
	make -C lib/my_all/
clean:
	rm -f *~ *.o
	rm -f lib/*~
	rm -f include/*
	rm -f src/*.o src/*~
	rm -f lib/*.a
	make fclean -C lib/my/
	make fclean -C lib/my_all/
fclean : clean
	 rm -f $(NAME)
re:	fclean all
