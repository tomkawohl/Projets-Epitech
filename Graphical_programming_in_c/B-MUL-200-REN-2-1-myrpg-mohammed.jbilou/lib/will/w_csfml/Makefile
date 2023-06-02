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

RMV_WAVE	=	*~

RMV_O	=	*.o

clean:
	rm -f $(RMV_WAVE)
	rm -f src/$(RMV_WAVE) src/$(RMV_O)
	rm -f src/window/$(RMV_WAVE) src/window/$(RMV_O)
	rm -f src/obj/$(RMV_WAVE) src/obj/$(RMV_O)
	rm -f src/w_clock/$(RMV_WAVE) src/w_clock/$(RMV_O)
fclean : clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re:	fclean all
