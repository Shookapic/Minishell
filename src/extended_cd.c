/*
** EPITECH PROJECT, 2023
** extcd
** File description:
** extended_cd
*/

#include "../include/my.h"
#include "../include/shell_struct.h"

int not_dir(char *str)
{
    if (isatty(0) == 1) {
        my_putstr_error(str);
        write(2, ": Not a directory.\n", 20);
        return 1;
    }else {
        my_putstr_error(str);
        write(2, ": Not a directory.\n", 20);
        exit(84);
    }
}

int perm(char *str)
{
    if (errno == EACCES) {
        if (isatty(0) == 1) {
            my_putstr_error(str);
            write(2, ": Permission denied.\n", 22);
            return 84;
        }else {
            my_putstr_error(str);
            write(2, ": Permission denied.\n", 22);
            exit(84);
        }
    }
    return 0;
}

int my_error(char *str)
{
    DIR *open = opendir(str);
    if (perm(str) == 84) {
        closedir(open);
        return 84;
    }
    if (errno == ENOTDIR) {
        not_dir(str);
    } else {
        if (isatty(0) == 1) {
            my_putstr_error(str);
            write(2, ": No such file or directory.\n", 30);
            return 84;
        }else {
            my_putstr_error(str);
            write(2, ": No such file or directory.\n", 30);
            exit(84);
        }
    }
    closedir(open);
    return 0;
}

int cd_ext_ext(shell_t *shell, int i)
{
    if (shell->cmd[1] == NULL) {
        if (chdir(&shell->env[i][5]) == -1) {
            my_error(&shell->env[i][5]);
        }
    }else {
        if (chdir(shell->cmd[1]) == -1) {
            my_error(shell->cmd[1]);
        }
    }
    return 0;
}
