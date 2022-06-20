/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-hippolyte.aubert
** File description:
** main
*/

#include "../include/my.h"

int print_help(void)
{
    my_printf("USAGE\n./asm file_name[.s]\nDESCRIPTION\nfile_name file in \
assembly language to be converted into file_name.cor, an executable in the \
Virtual Machine.\n");
    return 0;
}

char *get_part(char *str, int start, int end)
{
    char *new = malloc(sizeof(char) * (end - start + 1));
    int i = 0;

    for (; start != end; start++, i++)
        new[i] = str[start];
    new[i] = 0;
    return new;
}

char **get_file(char const *path)
{
    int fd = open(path, O_RDONLY);
    char *file = NULL;
    int size = 0;

    size = lseek(fd, 0, SEEK_END);
    lseek(fd, 0, SEEK_SET);
    file = malloc(sizeof(char) * (size + 1));
    if (read(fd, file, size) == -1)
        return NULL;
    file[size] = 0;
    return my_strtok(file, "\n");
}

int main(int argc, char **argv)
{
    char **map = NULL;
    clean_t *cleaned = NULL;

    if (argc != 2)
        return 84;
    if (my_strcmp(argv[1], "-h") == 0)
        return print_help();
    map = get_file(argv[1]);
    if (map == NULL)
        return 84;
    cleaned = clean_map(map, argv[1]);
    if (cleaned == NULL)
        return 84;
    return push_file(cleaned, argv[1]);
}
