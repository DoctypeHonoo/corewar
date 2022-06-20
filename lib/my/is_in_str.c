/*
** EPITECH PROJECT, 2022
** B-CPE-200-MPL-2-1-lemin-guillaume.lemoine
** File description:
** is_in_str
*/

int is_in_str_2(char *str, char *tf, int i)
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

int is_in_str(char *str, char *tf)
{
    int i = 0;

    for (; str[i] != '\0'; i++) {
        if (str[i] == tf[0] && is_in_str_2(str, tf, i + 1))
            return i;
    }
    return -1;
}
