/*
** EPITECH PROJECT, 2023
** find_symbol
** File description:
** find_symbol
*/

#include "../include/my.h"
#include "../include/shell_struct.h"

void get_path_ocmd(shell_t *shell)
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
        shell->tmp = my_strconcat(path2[j],
        my_strconcat("/", shell->m_cmds[0]));
        if (access(shell->tmp, F_OK) == 0) {
            return;
        }
    }
}

int all_bin_ocmd(shell_t *shell)
{
    int a , exc, signal = 0; shell->tmp = shell->one_cmd;
    if (access(shell->tmp, F_OK) != 0) {
        my_putstr_error(shell->tmp);
        my_putstr_error(": Command not found.\n");
        exit(1);
    } else {
        a = fork();
        if (a == 0) {
            exc = execve(shell->one_cmd, shell->m_cmds, shell->env);
        } else {
            waitpid(a, &signal, 0);
            siginit(signal);
            return 0;
        }
        if (exc == -1) {
            my_putstr_error(shell->cmd[0]);
            my_putstr_error(": Permission denied.\n");
            exit(1);
        }
    }return 0;
}

int execute_this_ocmd(shell_t *shell)
{
    get_path_ocmd(shell);
    if (shell->tmp == NULL) {
        return 1;
    }
    int sig = 0;
    int clone = fork();
    if (clone == 0) {
        execve(shell->tmp, shell->m_cmds, shell->env);
    } else {
        waitpid(clone, &sig, 0);
        siginit(sig);
        return 0;
    }
    if (execute_this_ext(shell, clone) == 1)
        exit(1);
    return 1;
}

int loop_condition_ocmd(shell_t *shell)
{
    function_t shell_func[] = {
        {"exit", my_exit},
        {"env", my_env},
        {"setenv", my_setenv},
        {"unsetenv", my_unsetenv},
        {"cd", my_cd},
        {NULL, NULL}
    };
    for (int i = 0; shell_func[i].str != NULL; i++) {
        if (my_strcmp(shell_func[i].str, shell->m_cmds[0]) == 0) {
            shell_func[i].fct(shell);
            free(shell->tmp);
            return 0;
        }
    }
    if (execute_this_ocmd(shell) == 1)
        return all_bin_ocmd(shell);
    return 0;
}

int find_symbol(char *str, char symbol)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == symbol)
            return 1;
    }
    return 0;
}
