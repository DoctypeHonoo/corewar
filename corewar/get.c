/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-hippolyte.aubert
** File description:
** get
*/

#include "../include/my.h"

int find_str(char *str, char *tf, int i)
{
    int j = 1;

    for (; tf[j] && str[i]; j++, i++) {
        if (str[i] != tf[j])
            return 0;
    }
    if (str[i] || (str[i] == 0 && tf[j] == 0))
        return 1;
    return 0;
}

int my_strstr(char *str, char *tf)
{
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] == tf[0] && find_str(str, tf, i + 1))
            return i;
    }
    return -1;
}

int count_champs(char **argv)
{
    int count = 0;
    for (int i = 1; argv[i]; i++)
        if (my_strstr(argv[i], ".cor") != -1)
            count++;
    return count;
}

char **get_champ_files(char **argv)
{
    int size = count_champs(argv);
    char **array = malloc(sizeof(char *) * size + 1);

    for (int i = 1, j = 0; argv[i]; i++) {
        array[i] = malloc(sizeof(char) * (my_strlen(argv[j]) + 1));
        if (my_strstr(argv[i], ".cor") != -1) {
            array[j] = argv[i];
            j++;
        }
    }
    return array;
}
