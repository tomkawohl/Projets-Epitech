/*
** EPITECH PROJECT, 2022
** src
** File description:
** src.h
*/

#ifndef SRC_H_
    #define SRC_H_
    #define UNUSED __attribute((unused))
    #define _GNU_SOURCE
    #define ERROR 84
    #define END 3
    #define SPACE ' '
    #define RESET 0
    #define ADD_NAME 1
    #define ASSIGN 2
    #define DELETE 3
    #define PWD 4

    #include "../lib/tools/include/tools.h"
    #include "../lib/w_printf/include/w_printf.h"
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <limits.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <string.h>
    #include <dirent.h>
    #include <errno.h>

char *get_input(char **env);
int handle_input(char *input, char **env);
char **get_name_arg(char *input);
void error_command_not_found(char *name);
int is_input_empty(char *input);
char *input_clean_space(char *input);
int count_words_input_clean(char *input);
void free_exit(char *path, char **name_arg, char **env, char *input);
void exit_fork(char *path, char **name_arg, char **env, char *input);

/* this version of env is more stable */
/*--------------[MANAGE ENV]----------------------*/
char **m_copy_env(char **env);
char **m_add_name_env(char **env, char *name);
int m_is_var_in_env(char **env, char *search);
char **m_assign_var_env(char **env, char *name, char *value);
int m_get_index_var(char **env, char *name);
char **m_delete_var_env(char **env, char *var);
int verify_name_var(char *name);
char **change_env_add_name(char **env, char **arg);
char **change_env_assign(char **env, char **arg);
char **change_env_delete(char **env, char **arg);

/*--------------[ENV]----------------------*/
char *z_get_env(char **env, char *search);
void add_var_to_env(char ***env, char *name, char *value);
void add_name_var_env(char ***env, char *name);
void copy_env(char **env, char **env_copy, unsigned int length);
int is_var_in_env(char **env, char *search);
int is_env_freeable(int set);
int get_index_var(char **env, char *name);
void add_value_var_env(char ***env, char *name, char *value);
void assign_var_env(char ****env, char *name, char *value);
void delete_var_env(char ****env, char *var);
/* verify if env is allocated and changeable */
void verify_env(char ***env);

/*--------------[PROMPT]-------------------*/
void prompt_display(void);
int is_dir_personnal(char *where);
char *get_current_folder(char *path);

/*--------------[EXEC]---------------------*/
unsigned int count_arg(char **function);
int check_command(char *input, char **env);
int exec_cd(char *input, char **env);
void update_pwd(char *path, char **env);
int exec_echo(char *input);
int exec_exit(char *input);
int exec_env(char *input, char **env);
int exec_setenv(char *input, char **env);
int exec_unsetenv(char *input);
int get_return(int *set);
int verify_perm(char *path);
int exec_folder(char *path);
void print_cd_path_null(void);
void check_execve(char *path);
int cd_is_directory(char *path);
void cd_print_error_no_file(char *path);
void cd_print_error_perm(char *path);
int cd_check_nb_arg(char **path);

/*--------------[SIGNALS]------------------*/
void set_pid(void);
int z_get_pid(int *pid);
void handler_sig(int sig);
void check_sig(int status);

/*--------------[PATH]------------------*/
char *get_path(char **env, char *name);

/*--------------[CHANGE ENV]------------------*/
char **change_env(char **env, char *input);
int get_change_status(int set_status, int get);
char **change_pwd_env(char **env, char **arg);

/*--------------[DEBUG]--------------------*/
void print_env(char **env);

#endif /* SRC_H_ */
