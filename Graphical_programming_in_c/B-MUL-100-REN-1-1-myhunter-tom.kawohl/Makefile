##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##
SRC	=	src/main.c	\
		src/manage_mouse.c	\
		src/manage_events.c	\
		src/manage_window.c	\
		src/manage_sprites.c	\
		src/main_menu.c	\
		src/object.c	\
		src/destroy_ressources.c	\
		src/game/handle_game.c	\
		src/all_sprites.c	\
		src/game/ennemy.c	\
		src/game/manage_events_game.c	\
		src/text.c	\
		src/game/is_end.c	\
		src/game/analyse_end_game.c	\
		src/description.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

CFLAGS	=	-Wall -Wextra -I include/

LDFLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system	\
			-L./lib/ -lmy_printf -L./lib/ -lmy_all -lcsfml-audio
all:	$(NAME)

$(NAME):	copy_lib $(OBJ)
	gcc -o my_hunter $(OBJ) $(LDFLAGS)

copy_lib:
	cp src/src.h include/
	cp src/struct.h include/
	make -C lib/my_printf/
	make -C lib/my_all/
clean:
	rm -f *~ *.o
	rm -f lib/*~
	rm -f include/*
	rm -f src/*.o src/*~
	rm -f src/game/*.o src/game/*~
	rm -f lib/*.a
	make fclean -C lib/my_printf/
	make fclean -C lib/my_all/
	make fclean -C lib/list/
fclean : clean
	 rm -f $(NAME)
re:	fclean all
