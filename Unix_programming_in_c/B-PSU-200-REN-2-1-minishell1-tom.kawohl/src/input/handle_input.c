/*
** EPITECH PROJECT, 2022
** input
** File description:
** handle_input
*/
#include "src.h"

int parent_wait(int fork_pid)
{
    int check_pid = 0;
    int status = 0;
    do {
        check_pid = waitpid(fork_pid, &status, WUNTRACED | WCONTINUED);
        if (check_pid == -1) {
            break;
        }
    } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    if (WIFSIGNALED(status)) {
        check_sig(status);
        return (status);
    }
    return (WEXITSTATUS(status));
}

void free_exit(char *path, char **name_arg, char **env, char *input)
{
    if (path != NULL)
        free(path);
    if (name_arg != NULL)
        free_array_str2d(name_arg);
    if (env != NULL)
        free_array_str2d(env);
    if (input != NULL)
        free(input);
}

void exec_input(char *path, char **name_arg, char **env, char *input)
{
    int fork_pid = 0;
    static int return_exe = 0;
    fork_pid = fork();
    if (fork_pid < 0)
        return;
    if (fork_pid == 0) {
        if (exec_folder(path))
            exit_fork(path, name_arg, env, input);
        if (execve(path, name_arg, env) == -1) {
            check_execve(path);
            exit_fork(path, name_arg, env, input);
        }
        free_exit(path, name_arg, env, input);
    } else {
        return_exe = parent_wait(fork_pid);
        get_return(&(return_exe));
    }
}

int handle_input(char *input, char **env)
{
    int check_return = check_command(input, env);
    char **name_arg = NULL;
    char *path = NULL;
    int return_0 = 0;
    if (!input)
        return (1);
    if (is_input_empty(input)) {
        get_return(&return_0);
        return (0);
    }
    if (check_return != FALSE)
        return (check_return);
    name_arg = get_name_arg(input);
    if (name_arg == NULL)
        return (0);
    path = get_path(env, name_arg[0]);
    exec_input(path, name_arg, env, input);
    free(path);
    free_array_str2d(name_arg);
    return (0);
}
