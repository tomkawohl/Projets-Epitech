##
## EPITECH PROJECT, 2022
## setup
## File description:
## Makefile
##
SRC	=	src/main.c \
		\
		src/init_map/map_init.c \
		src/init_map/is_file_valid.c \
		src/init_map/abs.c \
		src/init_map/game_tools.c \
		src/init_map/init_horizontal.c \
		src/init_map/init_vertical.c \
		src/init_map/is_map_info_valid.c \
		src/init_map/init_collision.c \
		src/init_map/map_struct_init.c \
		\
		src/connect_player/config_game.c \
		src/connect_player/protocol_connection.c \
		src/connect_player/init_pid_enemy.c \
		src/connect_player/is_connected.c \
		src/connect_player/get_player.c \
		\
		src/map/all_map_init.c \
		src/map/map_display.c \
		src/map/free_map.c \
		src/map/attack_map.c \
		\
		src/game/game_handle.c \
		src/game/input.c \
		src/game/send_sig.c \
		src/game/sig_enemy.c \
		src/game/sig_host.c \
		src/game/game_host.c \
		src/game/game_enemy.c \
		src/game/handler_sig.c \
		src/game/game_early.c \
		\
		src/manage_error/handle_error.c \
		\
		src/state/state_handle.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -I include/

LDFLAGS	=	-L./lib/ \
			-l:libw_printf.a -L./lib/ -l:libtools.a

NAME	=	navy

all:	$(NAME)

$(NAME):	make_lib $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

make_lib:
	make -C lib/tools/
	make -C lib/w_printf/

clean:
	rm -f *~
	rm -f $(OBJ) $(addsuffix ~, $(SRC))

fclean : clean
	rm -f $(NAME)
	make fclean -C lib/tools/
	make fclean -C lib/w_printf/

debug: fclean
debug: CFLAGS += -g -pg
debug: LDFLAGS += -pg
debug: all

see_debug: grpof ./$(NAME) ./gmon.out \
rm gmon.out

re:	fclean all
