/*
** EPITECH PROJECT, 2022
** path
** File description:
** get_path
*/
#include "src.h"

int get_dir(char *pathname, char *name)
{
    DIR *dirp = opendir(pathname);
    struct dirent *directory;
        if (!dirp)
            return (-1);
    while ((directory = readdir(dirp)) != NULL) {
        if (!directory)
            return (-1);
        if (my_strcmp(directory->d_name, name) == 0) {
            closedir(dirp);
            return (TRUE);
        }
    }
    if (closedir(dirp) == -1)
        return (-1);
    return (-1);
}

int get_dir_all_path(char **all_path, char *name)
{
    int verify = -1;
    for (int i = 0; all_path[i] != NULL; i++) {
        verify = get_dir(all_path[i], name);
        if (verify == TRUE) {
            return (i);
        }
    }
    return (-1);
}

void free_path(char *path, char **all_path)
{
    free(path);
    free_array_str2d(all_path);
}

char *copy_name(char *name)
{
    char *copy = NULL;
    if (!name)
        return (NULL);
    copy = str_recat(copy, name);
    return (copy);
}

char *get_path(char **env, char *name)
{
    char *path = z_get_env(env, "PATH");
    char **all_path = NULL;
    int index = -1;
    char *real_path = NULL;
    if (path == NULL) {
        path = z_get_env(env, "SHELL");
        if (path == NULL) return (NULL);
        return (path);
    }
    all_path = str_delimiter_array(path, ':');
    index = get_dir_all_path(all_path, name);
    if (index == -1) {
        free_path(path, all_path);
        return (copy_name(name));
    }
    real_path = str_recat(real_path, all_path[index]);
    real_path = str_recat(real_path, "/");
    real_path = str_recat(real_path, name);
    free_path(path, all_path);
    return (real_path);
}
