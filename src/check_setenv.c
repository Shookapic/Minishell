/*
** EPITECH PROJECT, 2023
** check_setenv
** File description:
** check_setenv
*/

#include "../include/my.h"
#include "../include/shell_struct.h"

int check_char_num(char c)
{
    if (c < '0' || c > '9')
        return 1;
    return 0;
}

int check_malloc(char **new_env, char *n_key)
{
    if (new_env == NULL) {
        perror("Error allocating memory");
        free(n_key);
        return 84;
    }
    return 0;
}

int my_isalnum(char c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
    (c >= '0' && c <= '9'));
}

int check_setenv(char *name)
{
    if (!my_isalnum(name[0]) && name[0] != '_') {
        my_putstr_error("setenv: Variable name must begin with a letter.\n");
        return 84;
    }
    if (check_char_num(name[0]) == 0) {
        my_putstr_error("setenv: Variable name must begin with a letter.\n");
        return 84;
    }
    for (int i = 0; name[i] != '\0'; i++) {
        if (!my_isalnum(name[i]) && name[i] != '_') {
            my_putstr_error("setenv: Variable name must contain ");
            my_putstr_error("alphanumeric characters.\n");
            return 84;
        }
    }
    return 0;
}
