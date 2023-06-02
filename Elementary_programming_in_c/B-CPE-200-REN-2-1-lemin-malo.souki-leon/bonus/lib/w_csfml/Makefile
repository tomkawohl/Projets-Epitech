##
## EPITECH PROJECT, 2022
## w_csfml
## File description:
## Makefile
##

CFLAGS = -Wall -Werror

SRC	=	src/window/init_window.c \
		\
		src/obj/obj_sprite_create.c \
		src/obj/obj_destroy.c \
		src/obj/obj_set_rect.c \
		src/obj/obj_move_rect.c \
		src/obj/obj_hitbox.c \
		src/obj/obj_move.c \
		src/obj/obj_collision.c \
		src/obj/obj_collision_c_r.c \
		\
		src/w_clock/w_clock_init.c \
		src/w_clock/w_clock_update.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libw_csfml.a

all:	$(NAME)

$(OBJ): $(SRC)
    gcc -c -o $@ $< -L./../ -l:libtools.a

$(NAME):	$(OBJ)
	ar rsc $(NAME) $(OBJ)
	cp $(NAME) -t ../
clean:
	rm -f *~
	rm -f src/*~ src/*.o
	rm -f src/window/*~ src/window/*.o
	rm -f src/obj/*~ src/obj/*.o
	rm -f src/w_clock/*~ src/w_clock/*.o
fclean : clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re:	fclean all
