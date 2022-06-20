/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-hippolyte.aubert
** File description:
** get_parameters
*/

#include "../include/my.h"

int need_pcb(char *name)
{
    if (my_strcmp(name, "live") == 0)
        return 0;
    if (my_strcmp(name, "zjmp") == 0)
        return 0;
    if (my_strcmp(name, "fork") == 0)
        return 0;
    if (my_strcmp(name, "lfork") == 0)
        return 0;
    return 1;
}

uint32_t get_parameters(char **line)
{
    uint32_t size = 0;

    for (int i = 1; line[i]; i++) {
        if (is_index(line, i)) {
            size += IND_SIZE;
            continue;
        }
        if (is_register(line[i])) {
            size++;
            continue;
        }
        if (is_dir(line[i])) {
            size += DIR_SIZE;
            continue;
        }
        if (is_ind(line[i])) {
            size += IND_SIZE;
            continue;
        }
    }
    return size;
}

uint32_t parse_line(char **line, int j)
{
    uint32_t size = 0;

    if (my_strcmp(line[0], op_tab[j].mnemonique) == 0) {

        size++;
        if (need_pcb(line[0]))
            size++;
        size += get_parameters(line);
    }
    return size;
}
