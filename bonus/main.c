/*
** EPITECH PROJECT, 2022
** COREWAR
** File description:
** main
*/

#include "../include/op.h"
#include "../include/my.h"

sfRenderWindow *init_window(int w, int h, char *title)
{
    sfRenderWindow *window;

    sfVideoMode mode = {w, h, 32};
    window = sfRenderWindow_create(mode, title, sfFullscreen, NULL);
    return window;
}

int main(int ac, char **av)
{
    champgph_t *champions = {0};

    champions = init_all_champs(ac, av);
    process_game(champions, (ac - 1));
    return 0;
}
