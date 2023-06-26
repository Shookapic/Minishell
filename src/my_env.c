/*
** EPITECH PROJECT, 2023
** env
** File description:
** env
*/

#include "../include/my.h"
#include "../include/shell_struct.h"

int my_env(shell_t *shell)
{
    for (int i = 0; shell->env[i] != NULL; i++) {
        my_putstr(shell->env[i]);
        my_putchar('\n');
    }
    return 0;
}
