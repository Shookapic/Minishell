/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "../include/my.h"
#include "../include/shell_struct.h"

int my_redirection(shell_t *shell);

int loop_condition(shell_t *shell)
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
        if (my_strcmp(shell_func[i].str, shell->cmd[0]) == 0) {
            shell_func[i].fct(shell);
            free(shell->tmp);
            return 0;
        }
    }
    if (execute_this(shell) == 1)
        return all_bin(shell);
    return 0;
}

int main_loop(shell_t *shell)
{
    char **args = NULL;
    while (1) {
        if (isatty(0) == 1)
            write(1, "$ :", 3);
        if (getline(&shell->str, &shell->len, stdin) == -1)
            exit(0);
        if (my_strcmp(strtok(my_strdup(shell->str), " \t"), "\n") == 0)
            continue;
        int save_0 = dup(0);
        int save_1 = dup(1);
        args = my_str_to_word_array(shell->str, ";");
        for (int i = 0; args[i] != NULL; i++) {
            shell->str = args[i];
            shell->cmd = my_str_to_word_array(shell->str, " \n\t");
            my_redirection(shell);
            loop_condition(shell);
        }
        dup2(save_0, 0);
        dup2(save_1, 1);
    } return 0;
}

int main(int ac, char **av, char **env)
{
    (void) av;
    if (ac > 1)
        return 84;
    shell_t *shell = malloc(sizeof(shell_t));
    shell->str = NULL;
    shell->one_cmd = NULL;
    shell->m_cmds = NULL;
    shell->tmp = NULL;
    shell->cmd = NULL;
    shell->len = 0;
    shell->env = duparray(env);
    main_loop(shell);
    return 0;
}
