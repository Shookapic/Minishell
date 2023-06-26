/*
** EPITECH PROJECT, 2023
** my_redirection
** File description:
** my_redirection
*/

#include "../include/my.h"
#include "../include/shell_struct.h"

int my_redirection_right(shell_t *shell, int i, int flag)
{
    int fd = open(shell->cmd[i + 1], O_WRONLY | O_CREAT | flag, 0644);
    if (fd == -1) {
        my_putstr_error("Error: cannot open file.\n");
        return 1;
    }
    dup2(fd, 1);
    close(fd);
    shell->cmd[i] = NULL;
    return 0;
}

int my_redirection_left(shell_t *shell, int i)
{
    int fd = open(shell->cmd[i + 1], O_RDONLY);
    if (fd == -1) {
        my_putstr_error("Error: cannot open file.\n");
        return 1;
    }
    dup2(fd, 0);
    close(fd);
    shell->cmd[i] = NULL;
    return 0;
}

int my_redirection(shell_t *shell)
{
    for (int i = 0; shell->cmd[i]; i++) {
        if (my_strcmp(shell->cmd[i], ">") == 0)
            return (my_redirection_right(shell, i, O_TRUNC));
        if (my_strcmp(shell->cmd[i], ">>") == 0)
            return (my_redirection_right(shell, i, O_APPEND));
        if (my_strcmp(shell->cmd[i], "<") == 0)
            return (my_redirection_left(shell, i));
    }
    return 0;
}
