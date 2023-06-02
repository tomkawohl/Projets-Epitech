##
## EPITECH PROJECT, 2023
## Makefile_src
## File description:
## Makefile_src
##

SRC		=		src/main.c	\
				src/parcing/get_map.c	\
				src/algorithm/solve_maze.c	\
				src/algorithm/get_bag.c	\
				src/algorithm/draw_map.c	\

OBJ		=		$(SRC:.c=.o)

MSL		=		-I lib/msl/includes/msl

PSL		=		-I lib/msl/includes/psl

SSL		=		-I lib/msl/includes/ssl

CSL		=		-I lib/msl/includes/csl

MLIB	=		-I lib/msl/includes/

CFLAGS	=		-I includes/ $(MLIB) $(CSL) $(MSL) $(PSL) $(SSL)

LIB		=		lib/libmsl.a

all:	$(OBJ)
	make -C lib/msl/
	gcc -o solver $(OBJ) $(LIB) -Wall -Wextra -g -lm

clean:
	make fclean -C lib/msl/
	rm -rf lib/*.a
	rm -rf src/*.o
	rm -rf src/algorithm/*.o
	rm -rf src/parcing/*.o

coding-style:
	coding-style.sh . .
	cat coding-style-reports.log
	rm -rf coding-style-reports.log

fclean:	clean
	rm -rf solver

re:	fclean	all
