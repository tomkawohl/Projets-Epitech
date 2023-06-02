/*
** EPITECH PROJECT, 2022
** prompt
** File description:
** is_dir_personal
*/
#include "src.h"

int get_uid_user(char *uid_line)
{
    int uid = 0;
    for (int i = 0; uid_line[i] != '\0'; i++) {
        if (char_is_num(uid_line[i])) {
            uid = my_getnbr_int(&(uid_line[i]));
            return (uid);
        }
    }
    return (uid);
}

int get_uid_folder(char *where)
{
    struct stat info;
    char *real_path = NULL;
    if (!where)
        return (-1);
    real_path = str_recat(real_path, "../");
    real_path = str_recat(real_path, get_current_folder(where));
    z_printf("\nreal_path = %s\n", real_path);
    if (stat(real_path, &info) != 0)
        return (-1);
    return (info.st_uid);
}

int is_dir_personnal(char *where)
{
    char *get_uid = file_to_str_stat("/proc/self/status");
    char **get_uid_2d = NULL;
    int i = 0;
    int uid_user = 0;
    int uid_folder = 0;
    if (!get_uid) return (FALSE);
    uid_folder = get_uid_folder(where);
    if (uid_folder == -1) return (FALSE);
    get_uid_2d = str1d_to_str2d(get_uid);
    while (get_uid_2d[i] != NULL) {
        if (my_strncmp(get_uid_2d[i], "Uid", 3) == 0) {
            uid_user = get_uid_user(get_uid_2d[i]);
            break;
        }
        i++;
    }
    if (uid_folder == uid_user) return (TRUE);
    free_array_str2d(get_uid_2d);
    free(get_uid);
    return (FALSE);
}
