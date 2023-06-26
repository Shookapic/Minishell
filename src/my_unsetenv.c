/*
** EPITECH PROJECT, 2023
** unsetenv
** File description:
** my_unsetenv
*/

#include "../include/my.h"
#include "../include/shell_struct.h"

// check if the input is valid
int is_key_valid(const char *name)
{
    if (name == NULL || name[0] == '\n') {
        my_putstr_error("unsetenv: Too few arguments.\n");
        return 1;
    }
    return 0;
}

// search for the index of a variable in the env
int search_var_index(shell_t *shell, char *name)
{
    for (int i = 0; shell->env[i] != NULL; i++) {
        if (my_strncmp(shell->env[i], name, my_strlen(name)) == 0 &&
            shell->env[i][my_strlen(name)] == '=') {
            return i;
        }
    }
    return -1;
}

int find_key(shell_t *shell, char *name)
{
    char **tmp = NULL;
    for (int i = 0; shell->env[i] != NULL; i++) {
        tmp = my_str_to_word_array(shell->env[i], "=");
        if (my_strcmp(tmp[0], name) == 0) {
            return i;
        }
    }
    return -1;
}

// remove a variable from the env
char **remove_var(shell_t *shell, char *name)
{
    int save = 0;
    int res = 0;
    int j = 0;
    if ((res = find_key(shell, name)) == -1)
        return shell->env;
    else
        save = my_envlen(shell->env);
    char **tab = malloc(sizeof(char *) * save);
    for (int a = 0; shell->env[a] != NULL; a++) {
        if (a != res) {
            tab[j] = my_strdup(shell->env[a]);
            j++;
        }
    }
    tab[j] = NULL;
    return tab;
}

// unset an environment variable
int my_unsetenv(shell_t *shell)
{
    shell->name = shell->cmd[1];
    shell->value = shell->cmd[2];
    for (int j = 0; shell->cmd[j] != NULL; j++) {
        if (is_key_valid(shell->cmd[j]) != 0)
            return 84;
        shell->env = remove_var(shell, shell->cmd[j]);
    }
    return 0;
}
