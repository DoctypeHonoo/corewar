/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-hippolyte.aubert
** File description:
** param_type
*/

#include "../include/my.h"

int is_register(char *str)
{
    if (str[0] == 'r')
        return 1;
    return 0;
}

int is_dir(char *str)
{
    if (str[0] == '%' && str[1] != ':')
            return 1;
    return 0;
}

int is_label(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == ':' && i != 0 && str[i - 1] != '%')
            return 1;
    return 0;
}

int is_ind(char *str)
{
    if (str[0] == '%' && str[1] == ':')
        return 1;
    return 0;
}

int is_index(char **line, int i)
{
    if (my_strcmp(line[0], "zjmp") == 0 || my_strcmp(line[0], "fork") == 0)
        return 1;
    if (my_strcmp(line[0], "ldi") == 0 && (i == 1 || i == 2))
        return 1;
    if (my_strcmp(line[0], "sti") == 0 && is_register(line[i]) == 0)
        return 1;
    return 0;
}
