/*
** EPITECH PROJECT, 2022
** 1
** File description:
** main
*/

#include "../include/my.h"

int print_help(void)
{
    my_printf("USAGE\n./corewar [-dump nbr_cycle] [[-n prog_number] [-a\
 load_address] prog_name] ...\nDESCRIPTION\n-dump nbr_cycle dumps the memory\
 after the nbr_cycle execution (if the round isn’t already over) with the\
 following format: 32 bytes/line in hexadecimal (A0BCDEFE1DD3...)\n\
-n prog_number sets the next program’s number. By default, the first free\
 number in the parameter order\n-a load_address sets the next program’s loa\
ding address. When no address is specified, optimize the addresses so that t\
he processes are as far away from each other as possible. The addresses are\
 MEM_SIZE modulo.\n");
    return 0;
}

int main(int argc, char **argv)
{
    champ_t champ = init_champ(argv[1], count_champs(argv));
    champ_t cham = init_champ(argv[2], count_champs(argv));

    if (argc == 2) {
        if (my_strcmp(argv[1], "-h") == 0)
            return print_help();
    } else {
        my_printf("%d\n", champ.id);
        my_printf("%s\n", champ.name);
        my_printf("%s\n", champ.ins);
        my_printf("%s\n", cham.ins);
    }
    return 0;
}

// int main(int argc, char **argv)
// {
//     (void)argc;
//     char **arr = get_champ_files(argv);
//     printf("%d\n", count_champs(argv));
//     for (int i = 0; i < count_champs(argv); i++)
//         printf("%s\n", arr[i]);
//     return 0;
// }
