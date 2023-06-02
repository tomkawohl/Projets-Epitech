##
## EPITECH PROJECT, 2022
## setup
## File description:
## Makefile
##
SRC	=	src/main.c	\
		\
		src/input/get_input.c				\
		src/input/handle_input.c			\
		src/input/get_name_arg.c			\
		src/input/error_input.c				\
		src/input/is_input_empty.c			\
		src/input/input_clean_space.c		\
		src/input/get_input_clean_space.c	\
		src/input/exit_fork.c				\
		\
		src/env/z_get_env.c			\
		src/env/add_var_to_env.c	\
		src/env/add_name_var_env.c	\
		src/env/assign_var_env.c	\
		src/env/is_var_in_env.c		\
		src/env/is_env_freeable.c	\
		src/env/get_index_var.c		\
		src/env/add_value_var_env.c	\
		src/env/delete_var_env.c	\
		src/env/verify_env.c		\
		\
		src/manage_env/copy_env.c			\
		src/manage_env/m_add_name_env.c		\
		src/manage_env/m_is_var_in_env.c	\
		src/manage_env/m_assign_var_env.c	\
		src/manage_env/m_get_index_var.c	\
		src/manage_env/m_delete_var_env.c	\
		\
		src/prompt/prompt_display.c		\
		src/prompt/is_dir_personal.c	\
		\
		src/exec/count_arg.c			\
		src/exec/check_command.c		\
		src/exec/exec_cd.c				\
		src/exec/exec_cd_update_pwd.c	\
		src/exec/exec_echo.c			\
		src/exec/exec_exit.c			\
		src/exec/exec_env.c				\
		src/exec/exec_setenv.c			\
		src/exec/exec_unsetenv.c		\
		src/exec/get_return.c			\
		src/exec/verify_perm.c			\
		src/exec/exec_folder.c			\
		src/exec/cd_path_null.c			\
		src/exec/check_execve.c			\
		src/exec/cd_is_directory.c		\
		src/exec/cd_print_error.c		\
		src/exec/cd_check_nb_arg.c		\
		\
		src/signals/z_get_pid.c		\
		src/signals/handler_sig.c	\
		src/signals/check_sig.c		\
		\
		src/path/get_path.c	\
		\
		src/change_env/get_change_status.c		\
		src/change_env/change_env.c				\
		src/change_env/verify_name_var.c		\
		src/change_env/change_env_add_name.c	\
		src/change_env/change_env_assign.c		\
		src/change_env/change_env_delete.c		\
		src/change_env/change_env_pwd.c			\
		\
		src/debug/print_env.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -I include/

LDFLAGS	=	-L./lib/
LDFLAGS +=	-l:libw_printf.a -L./lib/ -l:libtools.a

NAME	=	mysh

all:	$(NAME)

$(NAME):	make_lib $(OBJ)
	@ gcc -o $(NAME) $(OBJ) $(LDFLAGS)

.c.o:
	@ gcc $(CFLAGS) -c $< -o $@
	@ echo "$< -> $@"

make_lib:
	@ $(MAKE) -sC lib/tools/
	@ $(MAKE) -sC lib/w_printf/

clean:
	@ $(RM) *~
	@ $(RM) $(OBJ) $(addsuffix ~, $(SRC))

fclean : clean
	@ $(RM) $(NAME)
	@ make fclean -sC lib/tools/
	@ make fclean -sC lib/w_printf/

debug: CFLAGS += -g -pg
debug: LDFLAGS += -pg
debug: fclean all

see_debug: gprof ./$(NAME) ./gmon.out \
rm gmon.out

re:	fclean all

.PHONY: all make_lib clean fclean debug see_debug re
