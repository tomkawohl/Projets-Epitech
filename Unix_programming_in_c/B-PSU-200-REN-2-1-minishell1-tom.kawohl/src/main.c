/*
** EPITECH PROJECT, 2022
** src
** File description:
** main
*/
#include "src.h"

/* by copying and restoring the initial env */
/* isatty for ctrl + d */
/* exe bin who aren't in path like ./Destop/a.out */
int main(int ac, UNUSED char **av, char **env)
{
    int is_activ = TRUE;
    char *input = NULL;
    int is_end = FALSE;
    char **env_copy = NULL;

    if (ac != 1 || env == NULL) return (84);
    env_copy = m_copy_env(env);
    if (!env_copy) return (84);
    while (is_activ == TRUE) {
        prompt_display();
        input = get_input(env_copy);
        is_end = handle_input(input, env_copy);
        env_copy = change_env(env_copy, input);
        if (input != NULL)
            free(input);
        if (is_end == END)
            break;
    }
    free_array_str2d(env_copy);
    return (get_return(NULL));
}
