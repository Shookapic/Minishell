/*
** EPITECH PROJECT, 2023
** my_setenv
** File description:
** my_setenv
*/

#include "../include/my.h"
#include "../include/shell_struct.h"

int is_input_valid(char *name, shell_t *shell)
{
    if (shell->cmd[2] != NULL) {
        if (shell->cmd[3] != NULL) {
            my_putstr_error("setenv: Too many arguments.\n");
            return 84;
        }
    }
    if (name == NULL) {
        my_env(shell);
        return 84;
    }
    if (check_setenv(name) == 84)
        return 84;
    return 0;
}

int my_envlen(char **array)
{
    int i = 0;
    while (array[i] != NULL)
        i++;
    return i;
}

int search_existing_var(shell_t *shell)
{
    for (int i = 0; shell->env[i] != NULL; i++) {
        if (my_strncmp(shell->env[i], shell->name,
        my_strlen(shell->name)) == 0 &&
        shell->env[i][my_strlen(shell->name)] == '=') {
            shell->env[i] = shell->param;
            return 1;
        }
    }
    return 0;
}

int my_setenv(shell_t *shell)
{
    shell->name = shell->cmd[1];
    shell->value = shell->cmd[2];
    int i = my_envlen(shell->env);
    if (is_input_valid(shell->name, shell) == 84)
        return 84;
    int j = 0;
    shell->param = my_strconcat(shell->name, my_strconcat("=", shell->value));
    if (search_existing_var(shell) == 1) {
        return 1;
    }
    char **new_env = malloc(sizeof(char *) * (i + 2));
    char **n_env = duparray(shell->env);
    for (; n_env[j] != NULL; j++)
        new_env[j] = my_strdup(shell->env[j]);
    new_env[j] = my_strdup(shell->param);
    new_env[j + 1] = NULL;
    shell->env = new_env;
    return 0;
}
