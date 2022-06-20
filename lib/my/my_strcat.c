/*
** EPITECH PROJECT, 2021
** my_strcat.c
** File description:
** function that concatenates two strings
*/

#include "../../include/my.h"

char *my_strcat(char *dest, char *src)
{
    char *new = NULL;
    int i = 0;
    int l = 0;
    int index = 0;

    for (; dest[i] != '\0'; i++);
    for (; src[l] != '\0'; l++);
    new = malloc(sizeof(char) * (i + l + 1));
    for (i = 0; dest[i] != '\0'; i++, index++)
        new[index] = dest[i];
    for (l = 0; src[l] != '\0'; l++, index++)
        new[index] = src[l];
    new[index] = 0;
    return new;
}
