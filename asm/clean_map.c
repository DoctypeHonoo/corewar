/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-hippolyte.aubert
** File description:
** clean_map
*/

#include "../include/my.h"

int check_if_next(char *str, int dots)
{
    int i = 0;

    for (i = dots; str[i] == ' ' && str[i] != '\0'; i++);
    if (str[i] == 0)
        return 0;
    return i;
}

char *remake_clean(clean_t *cleaned, int i, int dots)
{
    char *temp = NULL;

    if (check_if_next(cleaned->code[i], dots + 1) == 0)
        return NULL;
    temp = get_part(cleaned->code[i], check_if_next(cleaned->code[i], dots + 1),
    my_strlen(cleaned->code[i]));
    return temp;
}

clean_t *handle_errors(clean_t *cleaned)
{
    if (cleaned->name == NULL)
        return NULL;
    if (cleaned->comment == NULL)
        return NULL;
    if (my_strlen(cleaned->name) > PROG_NAME_LENGTH)
        return NULL;
    if (my_strlen(cleaned->comment) > COMMENT_LENGTH)
        return NULL;
    return cleaned;
}

int clean_map_2(char *map, int pos, clean_t *cleaned)
{
    if (is_in_str(map, ".name") != -1 && map[0] == '.') {
        if (my_strtok(map, "\"") != NULL)
            cleaned->name = my_strtok(map, "\"")[1];
        else
            cleaned->name = NULL;
    }
    if (is_in_str(map, ".comment") != -1 && map[0] == '.') {
        if (my_strtok(map, "\"") != NULL)
            cleaned->comment = my_strtok(map, "\"")[1];
        else
            cleaned->comment = NULL;
    }
    if (map[0] != '#' && map[0] != '\n' && map[0] != '.') {
        cleaned->code[pos] = concat_array(my_strtok(map, " \t\n"));
        return pos + 1;
    }
    return pos;
}

clean_t *clean_map(char **file, char *path)
{
    clean_t *cleaned = malloc(sizeof(clean_t));
    FILE *stream = fopen(path, "r");
    char *map = NULL;
    size_t sizee = 0;
    int pos = 0;
    int size = 0;

    for (int j = 0; file[j]; j++)
        if (file[j][0] != '#' && file[j][0] != '\n' && file[j][0] != '.')
            size++;
    cleaned->code = malloc(sizeof(char *) * (size + 1));
    while (getline(&map, &sizee, stream) != -1)
        pos = clean_map_2(map, pos, cleaned);
    cleaned->code[size - 1] = NULL;
    return handle_errors(cleaned);
}
