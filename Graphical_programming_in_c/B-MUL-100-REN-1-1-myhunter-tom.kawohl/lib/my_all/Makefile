##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC	=	my_putchar.c	\
		my_compute_power_rec.c	\
		my_compute_square_root.c	\
		my_find_prime_sup.c	\
		my_getnbr.c	\
		my_isneg.c	\
		my_is_prime.c	\
		my_put_nbr.c	\
		my_putstr.c	\
		my_revstr.c	\
		my_sort_int_array.c	\
		my_strcmp.c	\
		my_strcpy.c	\
		my_strlen.c	\
		my_strlowcase.c	\
		my_strncmp.c	\
		my_strncpy.c	\
		my_strstr.c	\
		my_strupcase.c	\
		my_swap.c	\
		my_strcat.c	\
		my_str_to_word_array.c

OBJ = $(SRC:.c=.o)

NAME	=	libmy_all.a
all: $(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) -t ../../lib/
	cp my_all.h -t ../../include/
clean:
	rm -f $(OBJ)
	rm -f *~
fclean:	clean
	rm -f $(NAME)
re:	fclean all
