/*
** EPITECH PROJECT, 2023
** cd
** File description:
** my_cd
*/

#include "../include/my.h"
#include "../include/shell_struct.h"

int cd_extend(shell_t *shell, int i)
{
    if (shell->cmd[1] != NULL && shell->cmd[1][0] == '~') {
        if (chdir(&shell->env[i][5]) == -1) {
            my_error(&shell->env[i][5]);
        }else
            return 1;
    }
    if (cd_ext_ext(shell, i) == 1)
        return 1;
    return 0;
}

int my_cd(shell_t *shell)
{
    int i = 0;
    int found = 0;
    while (shell->env[i] != NULL) {
        if (my_strncmp(shell->env[i], "HOME=", 5) == 0) {
            found = 1;
            break;
        }
        i++;
    }
    if (!found) {
        return 1;
    }
    cd_extend(shell, i);
    return 1;
}
