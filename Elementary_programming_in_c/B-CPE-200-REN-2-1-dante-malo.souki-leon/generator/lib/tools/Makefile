##
## EPITECH PROJECT, 2022
## tools
## File description:
## Makefile
##

CFLAGS = -Wall -Werror

SRC	=	src/char/char_is_num.c	\
		src/char/my_putchar.c	\
		src/char/char_is_alpha.c \
		\
		src/str/my_strlen.c	\
		src/str/my_putstr.c	\
		src/str/my_getnbr_int.c	\
		src/str/my_getnbr_float.c \
		src/str/my_strcpy.c \
		src/str/my_strncpy.c \
		src/str/my_revstr.c \
		src/str/my_strcmp.c \
		src/str/my_strstr.c \
		src/str/my_strncmp.c \
		src/str/str_is_alpha.c \
		src/str/str_is_num.c \
		src/str/my_strdup.c \
		src/str/str_cat.c \
		src/str/str_get.c \
		src/str/str_to_word_array.c \
		src/str/str_to_int_array.c \
		src/str/str_count_int.c \
		\
		src/int/int_is_negativ.c \
		src/int/int_is_overflow.c \
		src/int/int_to_string.c \
		src/int/my_putnbr.c \
		\
		src/array/str1d_to_str2d.c \
		src/array/free_array.c \
		src/array/print_array1d.c \
		src/array/print_array2d.c \
		\
		src/list/list_int_create.c \
		src/list/list_int_add.c \
		src/list/list_int_remove.c \
		src/list/list_int_display.c \
		src/list/list_int_get.c \
		src/list/list_create.c \
		src/list/list_add.c \
		src/list/list_remove.c \
		\
		src/w_file/file_to_str_stat.c \
		src/w_file/file_to_str_getline.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libtools.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rsc $(NAME) $(OBJ)
	cp $(NAME) -t ../
clean:
	rm -f *~
	rm -f src/char/*~ src/char/*.o
	rm -f src/str/*~ src/str/*.o
	rm -f src/int/*~ src/int/*.o
	rm -f src/array/*~ src/array/*.o
	rm -f src/list/*~ src/list/*.o
	rm -f src/w_file/*~ src/w_file/*.o

fclean : clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re:	fclean all
