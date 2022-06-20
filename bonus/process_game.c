/*
** EPITECH PROJECT, 2022
** graphique
** File description:
** process_game
*/

#include "../include/op.h"
#include "../include/my.h"

cw_t init_vm(champgph_t *champs, int nb)
{
    cw_t vm = {0};

    vm.window = init_window(1920, 1080, "VM");
    vm.delta_clock = sfClock_create();
    vm.bytes = init_bytes_tab(champs, nb);
    return vm;
}

void event_manager(cw_t *vm)
{
    while (sfRenderWindow_pollEvent(vm->window, &vm->event)) {
        if (vm->event.type == sfEvtClosed)
            sfRenderWindow_close(vm->window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(vm->window);
    }
}

void display_game(cw_t *vm)
{
    for (int i = 0; i < MEM_SIZE; i++) {
        sfRenderWindow_drawRectangleShape(vm->window,
            vm->bytes[i].carre, NULL);
        sfRenderWindow_drawRectangleShape(vm->window,
            vm->bytes[i].carre2, NULL);
        sfRenderWindow_drawText(vm->window, vm->bytes[i].text, NULL);
    }
}

void process_game(champgph_t *champs, int nb)
{
    cw_t vm = init_vm(champs, nb);
    sfTime delta;

    sfRenderWindow_setFramerateLimit(vm.window, 120);
    while (sfRenderWindow_isOpen(vm.window)) {
        delta_time(&vm, delta);
        event_manager(&vm);
        sfRenderWindow_clear(vm.window, sfBlack);
        display_game(&vm);
        sfRenderWindow_display(vm.window);
    }
}
