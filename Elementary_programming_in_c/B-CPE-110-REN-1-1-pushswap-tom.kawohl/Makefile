##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##
SRC	=	src/main.c	\
		src/list_int_display.c	\
		src/handle_l_a.c	\
		src/swap.c	\
		src/push.c	\
		src/list_sort.c	\
		src/push_swap.c	\
		src/handle_error.c	\
		src/rotate.c	\
		src/sort_to_5.c	\
		src/stack_get.c

OBJ	=	$(SRC:.c=.o)

NAME	=	push_swap

CFLAGS	=	-Wall -Wextra -I include/ -I lib/wlist/include/

LDFLAGS	=	-L./lib/ -lmy_printf -L./lib/ -lmy_all -L./lib/ -lwlist

all:	$(NAME)

$(NAME):	copy_lib $(OBJ)
	gcc -o push_swap $(OBJ) $(LDFLAGS)

copy_lib:
	cp src/src.h include/
	make -C lib/my_printf/
	make -C lib/my_all/
	make -C lib/wlist/
clean:
	rm -f *~ *.o
	rm -f lib/*~
	rm -f include/*
	rm -f src/*.o src/*~
	rm -f lib/*.a
	make fclean -C lib/my_printf/
	make fclean -C lib/my_all/
	make fclean -C lib/wlist/
fclean : clean
	 rm -f $(NAME)
re:	fclean all
