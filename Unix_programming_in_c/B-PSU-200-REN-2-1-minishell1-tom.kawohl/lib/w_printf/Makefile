##
## EPITECH PROJECT, 2022
## w_printf
## File description:
## Makefile
##

CFLAGS = -Wall -Werror

SRC	=	src/w_printf.c \
		src/conversion_exec.c \
		src/conv_c.c \
		src/conv_d.c \
		src/conv_s.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libw_printf.a

all:	$(NAME)

$(OBJ): $(SRC)
    gcc -c -o $@ $< -L./../ -l:libtools.a

$(NAME):	$(OBJ)
	ar rsc $(NAME) $(OBJ)
	cp $(NAME) -t ../
clean:
	rm -f *~
	rm -f src/*~ src/*.o
fclean : clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re:	fclean all
