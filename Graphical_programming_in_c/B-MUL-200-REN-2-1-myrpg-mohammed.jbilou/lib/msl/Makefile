##
## EPITECH PROJECT, 2023
## Makefile_my
## File description:
## Makefile_my
##

SRC		=		src/msl/msl_putchar.c	\
				src/msl/msl_isneg.c	\
				src/msl/msl_put_nbr.c	\
				src/msl/msl_putstr.c	\
				src/msl/msl_strlen.c	\
				src/msl/msl_swap.c	\
				src/msl/msl_getnbr.c	\
				src/msl/msl_itoa.c	\
				src/msl/msl_strcmp.c	\
				src/msl/msl_nbr_len.c	\
				src/msl/msl_revstr.c	\
				src/msl/msl_strcpy.c	\
				src/msl/msl_show_array.c	\
				src/msl/msl_compute_power_rec.c	\
				src/msl/msl_compute_square_root.c	\
				src/msl/msl_isprime.c	\
				src/msl/msl_find_prime.c	\
				src/msl/msl_strncpy.c	\
				src/msl/msl_strstr.c	\
				src/msl/msl_strncmp.c	\
				src/msl/msl_str_islower.c	\
				src/msl/msl_str_isupper.c	\
				src/msl/msl_str_isprintable.c	\
				src/msl/msl_strcat.c	\
				src/msl/msl_strncat.c	\
				src/msl/msl_str_isalpha.c	\
				src/msl/msl_strcase.c	\
				src/msl/msl_str_isnum.c	\
				src/msl/msl_strcapitalize.c	\
				src/msl/msl_charisalpha.c	\
				src/msl/msl_charisnum.c	\
				src/msl/msl_str_to_word_array.c	\
				src/msl/msl_memset.c	\
				src/psl/basic/psl_show_chain.c	\
				src/psl/basic/psl_show_int.c	\
				src/psl/basic/psl_show_tab.c	\
				src/psl/psl_piercing.c	\
				src/psl/psl_printf.c	\
				src/csl/Add_chain/csl_add_base.c	\
				src/csl/Add_chain/csl_add_bgn.c	\
				src/csl/Add_chain/csl_add_mid.c	\
				src/csl/Add_chain/csl_add_end.c	\
				src/csl/Del_chain/csl_rm_base.c	\
				src/csl/Del_chain/csl_rm_bgn.c	\
				src/csl/Del_chain/csl_rm_end.c	\
				src/csl/Del_chain/csl_rm_mid.c	\
				src/csl/Del_chain/csl_rm_chain.c	\
				src/ssl/ssl_new_sprite.c	\
				src/ssl/ssl_new_rectangle.c	\
				src/ssl/ssl_new_text.c	\
				src/ssl/ssl_new_circle.c	\

OBJ		=		$(SRC:.c=.o)

MSL		=		-I includes/msl

PSL		=		-I includes/psl

SSL		=		-I includes/ssl

CSL		=		-I includes/csl

CFLAGS	=		-I includes/ -Wall -Wextra $(CSL) $(MSL) $(PSL) $(SSL)

all: 	$(OBJ)
	ar -rc ../libmsl.a $(OBJ)

RMV_O	=	*.o

clean:
	rm -rf src/msl/$(RMV_O)
	rm -rf src/psl/$(RMV_O)
	rm -rf src/csl/Add_chain/$(RMV_O)
	rm -rf src/csl/Del_chain/$(RMV_O)
	rm -rf src/psl/basic/$(RMV_O)
	rm -rf src/ssl/$(RMV_O)

fclean:	clean

re:	fclean	all
