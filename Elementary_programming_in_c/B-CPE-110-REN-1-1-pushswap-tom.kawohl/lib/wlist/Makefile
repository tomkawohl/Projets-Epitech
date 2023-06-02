##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC	=	src/list_int_create.c	\
		src/list_int_add.c	\
		src/list_int_remove.c	\
		src/list_int_get.c

OBJ = $(SRC:.c=.o)

NAME	=	libwlist.a

all: $(NAME)

$(NAME):	copy_headers $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) -t ../../lib/
copy_headers:
	cp src/wlist.h -t include/
clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f include/*.h
fclean:	clean
	rm -f $(NAME)
re:	fclean all
