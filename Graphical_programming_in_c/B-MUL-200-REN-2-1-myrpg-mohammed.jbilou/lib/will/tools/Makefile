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
		src/str/str_len.c		\
		src/str/str_dup.c		\
		src/str/print_error.c	\
		src/str/str_find.c		\
		src/str/str_cmp.c		\
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
		src/array/check_malloc.c \
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

RMV_O	=	*.o

RMV_WAVE	=	*~

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rsc $(NAME) $(OBJ)
	cp $(NAME) -t ../
clean:
	rm -f $(RMV_WAVE)
	rm -f src/char/$(RMV_WAVE) src/char/$(RMV_O)
	rm -f src/str/$(RMV_WAVE) src/str/$(RMV_O)
	rm -f src/int/$(RMV_WAVE) src/int/$(RMV_O)
	rm -f src/array/$(RMV_WAVE) src/array/$(RMV_O)
	rm -f src/list/$(RMV_WAVE) src/list/$(RMV_O)
	rm -f src/w_file/$(RMV_WAVE) src/w_file/$(RMV_O)

fclean : clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re:	fclean all
