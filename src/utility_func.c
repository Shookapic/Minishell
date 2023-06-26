/*
** EPITECH PROJECT, 2023
** uf
** File description:
** utility_func
*/

#include "../include/my.h"

int my_strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;
    return i;
}

char *my_strdup(char *str)
{
    int len = my_strlen(str);
    char *dup = malloc(sizeof(char) * (len + 1));
    int i = 0;
    while (str[i] != '\0') {
        dup[i] = str[i];
        i++;
    }
    dup[i] = '\0';
    return dup;
}

char **duparray(char **array)
{
    int i = 0;
    while (array[i] != NULL)
        i++;
    char **dup = malloc(sizeof(char *) * (i + 1));
    i = 0;
    while (array[i] != NULL) {
        dup[i] = my_strdup(array[i]);
        i++;
    }
    dup[i] = NULL;
    return dup;
}

int my_strcmp(char *str, char *str2)
{
    int len1 = my_strlen(str);
    int len2 = my_strlen(str2);
    if (len1 != len2)
        return 1;
    int i = 0;
    while (str[i] != '\0' && str2[i] != '\0') {
        if (str[i] > str2[i])
            return 1;
        if (str[i] < str2[i])
            return 1;
        i++;
    }
    return 0;
}

int my_strncmp(char *str1, char *str2, int nb)
{
    for (int i = 0; i < nb; i++) {
        if (str1[i] > str2[i])
            return 2;
        if (str1[i] < str2[i])
            return -2;
    }
    return 0;
}
