/*
** EPITECH PROJECT, 2023
** shell_struct
** File description:
** shell_struct
*/

#pragma once

typedef struct shell_s {
    char **m_cmds;
    char **env;
    char **cmd;
    char *param;
    char *value;
    char *name;
    char *str;
    char *tmp;
    char *one_cmd;
    size_t len;
} shell_t;

typedef struct function_s {
    char *str;
    int (*fct)(shell_t *shell);
} function_t;
