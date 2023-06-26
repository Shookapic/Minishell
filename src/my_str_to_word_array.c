/*
** EPITECH PROJECT, 2022
** str_to_array
** File description:
** str_to_array
*/
#include "../include/my.h"
#include <stddef.h>
#include <stdlib.h>

int separaters(char const *str, char c)
{
    for (int i = 0; str[i]; i++)
        if (str[i] == c)
            return 1;
    return 0;
}

char *change_that(char const *sep, char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (separaters(sep, str[i]) == 1)
            str[i] = '\0';
    }
    return str;
}

int count_word(char const *str, char const *sep)
{
    int cnt = 0;
    int in_word = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (separaters(sep, str[i])) {
            in_word = 0;
        } else {
            (!in_word) ? cnt++, in_word = 1 : 0;
        }
    }
    return cnt;
}

char **my_str_to_word_array(char *str, char const *sep)
{
    if (str == NULL)
        return NULL;
    int y = 0;
    char *cpy = my_strdup(str);
    int nb_word = count_word(str, sep);
    char **dest = malloc(sizeof(char *) * (nb_word + 1));
    cpy = change_that(sep, cpy);
    for (int i = 0; i < my_strlen(str); i++) {
        while (cpy[i] == '\0')
            i++;
        dest[y] = my_strdup(cpy + i);
        i += my_strlen(dest[y]);
        y++;
    }
    dest[nb_word] = NULL;
    free(cpy);
    return dest;
}
