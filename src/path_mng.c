/*
** EPITECH PROJECT, 2023
** path_management
** File description:
** path_management
*/

#include "../include/my.h"
#include "../include/shell_struct.h"

char *check_path(char **path, shell_t *shell)
{
    if (path == NULL) {
        my_putstr_error(shell->cmd[0]);
        my_putstr_error(": Command not found.\n");
        return NULL;
    }
    return "";
}

void get_path(shell_t *shell)
{
    int a = 0;
    for (; shell->env[a] != NULL; a++) {
        if (my_strncmp(shell->env[a], "PATH=", 5) == 0)
            break;
    }
    char **path = my_str_to_word_array(shell->env[a], "=");
        if (path == NULL)
            return;
    char **path2 = my_str_to_word_array(path[1], ":");
    if (path2 == NULL)
        return;
    for (int j = 0; path2[j] != NULL; j++) {
        shell->tmp = my_strconcat(path2[j], my_strconcat("/", shell->cmd[0]));
        if (access(shell->tmp, F_OK) == 0) {
            return;
        }
    }
}
