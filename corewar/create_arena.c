/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-hippolyte.aubert
** File description:
** create_arena
*/

#include "../include/my.h"

char *create_arena(champ_t *champ, char **argv)
{
    char *arena = malloc(sizeof(char) * (MEM_SIZE * 2));
    int gap = MEM_SIZE * 2;
    int nb = count_champs(argv);

    return arena;
}

champ_t *init_champ_tab(int nb, char *filename)
{
    champ_t *tab = malloc(sizeof(champ_t) * nb);

    for (int i = 0; i < nb; i++)
        tab[i] = init_champ(filename, i + 1);
    return tab;
}

vm_t *init_vm(char **argv, char *filename)
{
    vm_t *vm = malloc(sizeof(vm_t));

    vm->arena = create_arena(vm->champ, argv);
    vm->nb_champ = count_champs(argv);
    vm->champ = init_champ_tab(count_champs(argv), filename);

    return vm;
}
