/*
** EPITECH PROJECT, 2022
** read_file.c
** File description:
** read file
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

off_t get_file_size(char const *filepath)
{
    struct stat statbuf;

    if (stat(filepath, &statbuf) == -1)
        return 84;
    return statbuf.st_size;
}

char *read_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *map;
    off_t fs = get_file_size(filepath);

    map = malloc(sizeof(char) * (fs + 1));
    if (!map || fd == -1 || fs == -1 || read(fd, map, fs) == -1)
        return NULL;
    map[fs] = '\0';
    close(fd);
    return map;
}
