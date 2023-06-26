/*
** EPITECH PROJECT, 2023
** uf3
** File description:
** utility_func_3
*/

#include "../include/my.h"
#include "../include/shell_struct.h"

void free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++) {
        free(array[i]);
    }
    free(array);
}
