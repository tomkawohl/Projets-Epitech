##
## EPITECH PROJECT, 2023
## Makefile_my
## File description:
## Makefile_my
##

SRC		=		src/ssl_new_sprite.c	\
				src/ssl_new_rectangle.c	\
				src/ssl_new_text.c	\
				src/ssl_new_circle.c	\

OBJ		=		$(SRC:.c=.o)

SSL		=		-I includes/ssl

CFLAGS	=		-I includes/ -Wall -Wextra $(SSL)

all: 	$(OBJ)
	ar -rc ../libmsl.a $(OBJ)

clean:
	rm $(OBJ)

fclean:	clean

re:	fclean	all
