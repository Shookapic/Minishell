/*
** EPITECH PROJECT, 2023
** my_exit
** File description:
** my_exit
*/

#include "../include/my.h"
#include "../include/shell_struct.h"

int my_exit(shell_t *shell)
{
    int nb = 0;
    if (shell->cmd[1] == NULL) {
        free_array(shell->env);
        free_array(shell->cmd);
        free(shell);
        exit(0);
    } else {
        nb = my_getnbr(shell->cmd[1]);
        free_array(shell->env);
        free_array(shell->cmd);
        free(shell);
        exit(nb);
    }
    return 0;
}
