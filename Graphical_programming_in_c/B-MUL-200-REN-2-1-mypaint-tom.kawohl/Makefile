##
## EPITECH PROJECT, 2022
## task02 Makefile
## File description:
## This will help compile code for task 02
##

HELPER	=	src/helper

INIT	=	src/init

RUN	=	src/run

EVENT	=	src/event

TOOLS	=	src/tools

LAYER	=	src/layer

LIST_TEXTURE	=	src/list_texture

INFO	=	src/info

GUI	=	src/gui

BUTTON = src/button

GUI_INFO	=	src/gui_info

PRIORITY_BUTTON = src/priority_button

BUTTON_PRESS_LEFT = src/button_press_left

SAVE_FILE	=	src/save_img

OPEN_FILE = src/open_file

SRC	=	src/main.c	\
		$(INIT)/init.c	\
		\
		$(RUN)/run.c	\
		$(RUN)/run_draw.c	\
		\
		$(EVENT)/handle_event.c	\
		$(EVENT)/zoom_event.c	\
		$(EVENT)/move_event.c	\
		$(EVENT)/save_file_event.c	\
		\
		$(TOOLS)/tool_init.c	\
		$(TOOLS)/tool_event.c	\
		\
		$(TOOLS)/pencil/pencil_init.c				\
		$(TOOLS)/pencil/pencil_destroy.c			\
		$(TOOLS)/pencil/pencil_event.c				\
		$(TOOLS)/pencil/pencil_draw.c				\
		$(TOOLS)/pencil/pencil_update.c				\
		$(TOOLS)/pencil/pencil_add_vertex_circle.c	\
		\
		$(LAYER)/layer_add.c		\
		$(LAYER)/layer_destroy.c	\
		$(LAYER)/layer_init.c		\
		$(LAYER)/layer_remove.c		\
		$(LAYER)/layer_event.c		\
		$(LAYER)/layer_draw.c		\
		\
		$(LIST_TEXTURE)/list_texture_init.c				\
		$(LIST_TEXTURE)/list_texture_add.c				\
		$(LIST_TEXTURE)/list_texture_remove.c			\
		$(LIST_TEXTURE)/list_texture_destroy.c			\
		$(LIST_TEXTURE)/list_texture_set_activ.c		\
		$(LIST_TEXTURE)/list_texture_remove_unactiv.c	\
		\
		$(INFO)/info_destroy.c	\
		\
		$(GUI)/init/gui_top_init.c	\
		$(GUI)/init/init_main_btn.c	\
		$(GUI)/event/gui_event.c	\
		$(GUI)/init/init_dd_btn.c	\
		\
		$(GUI_INFO)/gui_info_init.c				\
		$(GUI_INFO)/gui_info_draw.c				\
		$(GUI_INFO)/gui_info_draw2.c				\
		$(GUI_INFO)/gui_info_destroy.c			\
		$(GUI_INFO)/gui_info_event.c			\
		$(GUI_INFO)/gui_info_event_click.c		\
		$(GUI_INFO)/gui_info_rightbar_init.c	\
		$(GUI_INFO)/update_resize.c				\
		$(GUI_INFO)/update_resize2.c				\
		\
		$(HELPER)/get.c						\
		$(HELPER)/set1.c					\
		$(HELPER)/str_len.c					\
		$(HELPER)/str_dup.c					\
		$(HELPER)/str_cat.c					\
		\
		$(BUTTON)/button_init.c			\
		$(BUTTON)/button_destroy.c		\
		$(BUTTON)/button_set_text.c		\
		$(BUTTON)/topbar_init.c			\
		$(BUTTON)/button_is_clicked.c	\
		$(BUTTON)/rightbar_init.c		\
		\
		$(PRIORITY_BUTTON)/priority_button_init.c	\
		$(PRIORITY_BUTTON)/priority_button_remove.c	\
		$(PRIORITY_BUTTON)/priority_button_destroy.c\
		$(PRIORITY_BUTTON)/priority_button_add.c	\
		$(PRIORITY_BUTTON)/priority_button_draw.c	\
		$(PRIORITY_BUTTON)/priority_button_event.c	\
		\
		$(BUTTON_PRESS_LEFT)/help/help_press_left.c		\
		$(BUTTON_PRESS_LEFT)/pencil_btn_press_left.c	\
		$(BUTTON_PRESS_LEFT)/eraser_btn_press_left.c	\
		$(BUTTON_PRESS_LEFT)/new_file_press_left.c		\
		\
		$(BUTTON_PRESS_LEFT)/rightbar/pencil_size_press_left.c	\
		\
		$(SAVE_FILE)/init_texture.c	\
		$(SAVE_FILE)/save_img.c	\
		$(SAVE_FILE)/update_texture_size.c	\
		\
		$(OPEN_FILE)/open_file.c

# this will do the first step of compilation automatically
OBJ	=	$(SRC:.c=.o)
# this will only be used in the first step of compilation
CFLAGS	=	-I include

INSERT_LIB	=	-lcsfml-graphics -lcsfml-system \
			-lcsfml-audio -lcsfml-window    \
			-Llib/my -lmy -lm
NAME	=	my_paint

MAKEFLAGS	+=	--no-print-directory

all:	$(NAME)

$(NAME):	$(OBJ) compile_lib
	@ $(CC) -o $(NAME) $(SRC) $(CFLAGS) $(INSERT_LIB) -Wall -Wextra -g	\


compile_lib 	:
	@ $(MAKE) -C lib/my

clean:
	@ rm -f $(OBJ)

fclean:	clean
	@ rm -f $(NAME)
	@ cd lib/my/ && make fclean

re:	fclean all

fast:	fclean
	@ $(MAKE) -j

COUNT = 0
MAX_FILES = $(words $(SRC))

%.o: %.c
	@ $(eval COUNT=$(shell echo $$(($(COUNT) + 1))))

##	mkdir -p $(@D)
	@ $(CC) $(CFLAGS) -c $< -o $@

ifneq (,$(findstring j, $(MAKEFLAGS)))
	echo "$c =====> $@"
else
	@ python3 bar.py --stepno=$(COUNT) --nsteps=$(MAX_FILES)
endif
