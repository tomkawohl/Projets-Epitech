##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##
CFLAGS	=	-Wall -Wextra -I ../../include/

SRC	=

OBJ	=	$(SRC:.c=.o)

NAME	=	liblist.a

HEAD	=	list.h

all:	$(NAME)

$(NAME):	copy_headers $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
copy_headers:
	cp	$(HEAD) ../../include
clean:
	rm -f *.o *~ *#
fclean : clean
	 rm -f $(NAME)
re: fclean all
