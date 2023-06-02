##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##
SRC	=	my_printf.c	\
		conversion.c	\
		my_putchar.c	\
		my_put_nbr.c	\
		my_getnbr.c	\
		my_putstr.c	\
		my_put_nbr_float.c	\
		my_put_nbr_base.c	\
		my_put_nbr2.c	\
		my_strlen.c	\
		conv/conv_c.c	\
		conv/conv_d.c	\
		conv/conv_e.c	\
		conv/conv_b.c	\
		conv/conv_emaj.c	\
		conv/conv_f.c	\
		conv/conv_i.c	\
		conv/conv_o.c	\
		conv/conv_p.c	\
		conv/conv_percent.c	\
		conv/conv_s.c	\
		conv/conv_smaj.c	\
		conv/conv_u.c	\
		conv/conv_x.c	\
		conv/conv_xmaj.c	\
		conv/conv_g.c	\
		idec.c	\
		conv/conv_n.c	\
		sc.c	\
		length_l.c	\
		length/lengthl_d.c	\
		length/my_put_nbr_ld.c	\
		length/lengthl_i.c	\
		length/lengthl_o.c	\
		length/lengthl_u.c	\
		length/lengthl_x.c	\
		length/lengthl_xmaj.c	\
		my_itoa.c	\
		precision.c	\
		precision/precision_d.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

HEAD	=	my.h

all:	$(NAME)

$(NAME):	copy_headers $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
copy_headers:
	cp	$(HEAD) ../../include
clean:
	rm -f *.o *~ *#
	rm -f conv/*.o conv/*~ conv/*#
	rm -f length/*.o length/*~ length/*#
	rm -f precision/*.o precision/*~  precision/*#
fclean : clean
	 rm -f $(NAME)
re: fclean all
