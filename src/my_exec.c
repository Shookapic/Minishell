/*
** EPITECH PROJECT, 2023
** exec
** File description:
** my_exec
*/

#include "../include/my.h"
#include "../include/shell_struct.h"

void signal_handler(int pid)
{
    if (WTERMSIG(pid) == SIGSEGV)
        write(2, "Segmentation fault", 18);
    if (WTERMSIG(pid) == SIGFPE)
        write(2, "Floating exception", 18);
    if (WTERMSIG(pid) == SIGABRT)
        write(2, "Abort", 5);
    if (WTERMSIG(pid) == SIGBUS)
        write(2, "Bus error", 9);
    if (WCOREDUMP(pid))
        write(2, " (core dumped)\n", 15);
    else
        write(2, "\n", 1);
}

void siginit(int pid)
{
    if (WIFSIGNALED(pid)) {
        signal_handler(pid);
    }
}

int all_bin(shell_t *shell)
{
    int a , exc, signal = 0; shell->tmp = shell->cmd[0];
    if (access(shell->tmp, F_OK) != 0) {
        my_putstr_error(shell->cmd[0]);
        my_putstr_error(": Command not found.\n");
        exit(1);
    } else {
        a = fork();
        if (a == 0) {
            exc = execve(shell->cmd[0], shell->cmd, shell->env);
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

int execute_this_ext(shell_t *shell, int exc)
{
    if (exc == -1) {
        if (errno == ENOEXEC) {
            my_putstr_error(shell->cmd[0]);
            my_putstr_error(": Exec format error. Wrong Architecture.\n");
            return 1;
        }
        if (errno == EACCES) {
            my_putstr_error(shell->cmd[0]);
            my_putstr_error(": Permission denied.\n");
            return 1;
        } else {
            my_putstr_error(shell->cmd[0]);
            my_putstr_error(": Command not found.\n");
            return 1;
        }
    }
    return 0;
}

int execute_this(shell_t *shell)
{
    get_path(shell);
    if (shell->tmp == NULL) {
        return 1;
    }
    int sig = 0;
    int clone = fork();
    if (clone == 0) {
        execve(shell->tmp, shell->cmd, shell->env);
    } else {
        waitpid(clone, &sig, 0);
        siginit(sig);
        free(shell->tmp);
        return 0;
    }
    if (execute_this_ext(shell, clone) == 1)
        exit(1);
    return 1;
}
