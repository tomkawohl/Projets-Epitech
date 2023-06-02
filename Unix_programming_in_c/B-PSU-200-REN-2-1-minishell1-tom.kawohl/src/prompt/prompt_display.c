/*
** EPITECH PROJECT, 2022
** prompt
** File description:
** prompt_display
*/
#include "src.h"

char *get_current_folder(char *path)
{
    unsigned int count_bar = 0;
    unsigned int count = 0;
    if (!path)
        return (NULL);
    for (unsigned int i = 0; path[i] != '\0'; i++) {
        if (path[i] == '/')
            count_bar++;
    }
    for (unsigned i = 0; path[i] != '\0'; i++) {
        if (path[i] == '/')
            count++;
        if (count == count_bar)
            return (&(path[i + 1]));
    }
    return (NULL);
}

void prompt_display(void)
{
    z_printf("$ ");
}

/* not used : is_dir_personnal to display '~' or not */
/*
void prompt_display(char **env)
{
    char *logname = NULL;
    char *hostname = NULL;
    char *where = NULL;
    if (isatty(0) == 0)
        return;
    if (env == NULL)
        return;
    logname = z_get_env(env, "LOGNAME");
    hostname = z_get_env(env, "HOSTNAME");
    where = getcwd(where, PATH_MAX);
    z_printf("[%s@%s ", logname, hostname);
    z_printf("%s]$ ", get_current_folder(where));
    free (logname);
    free (hostname);
    if (where != NULL)
        free(where);
}
*/
