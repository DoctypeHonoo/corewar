/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-hippolyte.aubert
** File description:
** init_champions
*/

#include "../include/op.h"
#include "../include/my.h"

champgph_t *init_all_champs(int ac, char **av)
{
    champgph_t *champs = malloc(sizeof(champgph_t) * (ac - 1));
    char *instruction = NULL;
    int j = 0;

    for (int i = 1; i < ac; i++) {
        instruction = read_file(av[i]);
        champs[i - 1].champion = my_strtok(instruction, " ");
        for (; champs[i - 1].champion[j] != NULL; j++);
        champs[i - 1].size = j;
    }
    return champs;
}
