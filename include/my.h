/*
** EPITECH PROJECT, 2023
** my
** File description:
** my
*/

#pragma once

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdio.h>

#include "shell_struct.h"

char **my_str_to_word_array(char *str, char const *sep);
char **duparray(char **array);
char *my_strconcat(char *src_left, char *src_right);
char *my_strdup(char *src);
int check_malloc(char **new_env, char *n_key);
int execute_this_ext(shell_t *shell, int exc);
int my_strncmp(char *s1, char *s2, int n);
int loop_condition_ocmd(shell_t *shell);
int find_symbol(char *str, char symbol);
int cd_ext_ext(shell_t *shell, int i);
int loop_condition(shell_t *shell);
int my_strcmp(char *s1, char *s2);
int execute_this(shell_t *shell);
int my_unsetenv(shell_t *shell);
int my_getnbr(char const *str);
int my_setenv(shell_t *shell);
int check_setenv(char *name);
int all_bin(shell_t *shell);
int my_exit(shell_t *shell);
int my_envlen(char **array);
int my_env(shell_t *shell);
int my_cd(shell_t *shell);
int my_strlen(char *str);
int my_error(char *str);
int not_dir(char *str);
int perm(char *str);
void my_putstr_error(char *str);
void free_array(char **array);
void get_path(shell_t *shell);
void my_putchar_error(char c);
void my_putstr(char *str);
void my_putchar(char c);
void siginit(int pid);
