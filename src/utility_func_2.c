/*
** EPITECH PROJECT, 2023
** uf2
** File description:
** utility_func_2
*/

#include "../include/my.h"

char *my_strconcat(char *src_left, char *src_right)
{
    int i = 0;
    int j = 0;
    if (src_right == NULL)
        return src_left;
    char *dest = malloc(sizeof(char) *
    (my_strlen(src_left) + my_strlen(src_right) + 1));
    if (dest == NULL)
        return NULL;
    while (src_left[i] != '\0') {
        dest[i] = src_left[i];
        i++;
    }
    while (src_right[j] != '\0') {
        dest[i] = src_right[j];
        i++;
        j++;
    }
    dest[i] = '\0';
    return dest;
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putchar_error(char c)
{
    write(2, &c, 1);
}

void my_putstr(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i++;
    }
}

void my_putstr_error(char *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar_error(str[i]);
        i++;
    }
}
