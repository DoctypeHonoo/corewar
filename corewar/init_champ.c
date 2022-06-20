/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-hippolyte.aubert
** File description:
** read_file
*/

#include "../include/my.h"

char *get_champ_name(char *filename)
{
    int fd = open(filename, O_RDONLY);
    int hex = 0;
    int i = 0;

    char *name = malloc(sizeof(char) * PROG_NAME_LENGTH);
    read(fd, &hex, 4);
    for (; i < PROG_NAME_LENGTH - 4; i++) {
        read(fd, &hex, 1);
        name[i] = hex;
    }
    name[PROG_NAME_LENGTH] = 0;
    close(fd);
    return name;
}

char *get_champ_instructions(char *filename)
{
    int fd = open(filename, O_RDONLY);
    int hex = 0;
    int size = 1;
    char *skip = malloc(sizeof(char) * PROG_NAME_LENGTH + COMMENT_LENGTH + 16);
    char *instruct = malloc(sizeof(char) * size + 1);
    int i = 0;

    read(fd, skip, PROG_NAME_LENGTH + COMMENT_LENGTH + 16);
    while (read(fd, &hex, 1) > 0) {
        size += 2;
        instruct = realloc(instruct, size);
        if (hex <= 16)
            instruct[i++] = '0';
        convert_to_hex(hex, instruct, i);
        i += (hex <= 16) ? 1 : 2;
    }
    instruct[size] = 0;
    close(fd);
    return instruct;
}

champ_t init_champ(char *filename, int nb)
{
    champ_t champ = {0};

    champ.id = nb;
    champ.name = get_champ_name(filename);
    champ.ins = get_champ_instructions(filename);
    champ.lives = 0;

    return champ;
}
