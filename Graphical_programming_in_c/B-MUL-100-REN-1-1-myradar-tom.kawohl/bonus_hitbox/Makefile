##
## EPITECH PROJECT, 2022
## setup
## File description:
## Makefile
##
SRC	=	src/main.c	\
		src/parse_file.c \
		src/radar.c \
		src/count_element.c \
		src/destroy_element.c \
		src/simulation.c \
		src/init_element.c \
		src/planes_display.c \
		src/planes_move.c \
		src/towers_display.c \
		src/events.c \
		src/collision_rect.c \
		src/collision.c \
		src/text.c \
		src/description.c \
		src/angle.c \
		src/error.c \
		src/init_direction.c \
		src/matrix.c \
		\
		src/debug/debug.c \
		src/debug/debug_init_element.c \
		src/debug/debug_simulation.c \
		src/debug/debug_event.c \
		src/debug/debug_display.c \
		src/debug/debug_rotate.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -I include/

LDFLAGS	=	-L./lib/ -l:libw_csfml.a -L./lib/ \
			-l:libw_printf.a -L./lib/ -l:libtools.a

CSFMLFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system

NAME	=	my_radar

all:	$(NAME)

$(NAME):	copy_headers make_lib $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS) $(CSFMLFLAGS) -lm

copy_headers:
	cp src/src.h include/

make_lib:
	make -C lib/tools/
	make -C lib/w_printf/
	make -C lib/w_csfml/

clean:
	rm -f *~
	rm -f src/*~ src/*.o
	rm -f src/debug/*~ src/debug/*.o

fclean : clean
	rm -f $(NAME)
	make fclean -C lib/tools/
	make fclean -C lib/w_printf/
	make fclean -C lib/w_csfml

re:	fclean all
