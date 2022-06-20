/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-hippolyte.aubert
** File description:
** concat_array
*/

#include "../../include/my.h"

int get_size(char **array)
{
    int i = 0;

    for (; array[i]; i++);
    return i;
}

int get_letters(char **array)
{
    int size = 0;
    int j = 0;

    for (int i = 0; array[i]; i++) {
        for (j = 0; array[i][j] != '\0'; j++);
        size += j;
    }
    return size;
}

char *concat_array(char **array)
{
    int size = get_size(array);
    int letters = get_letters(array);
    char *str = malloc(sizeof(char) * (letters + size));
    int k = 0;

    for (int i = 0; array[i]; i++) {
        for (int j = 0; array[i][j] != '\0'; j++, k++)
            str[k] = array[i][j];
        str[k] = ' ';
        k++;
    }
    str[k - 2] = '\0';
    return str;
}
