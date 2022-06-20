/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-romain.very
** File description:
** delta
*/

#include "../include/op.h"
#include "../include/my.h"

void delta_time(cw_t *vm, sfTime delta_time)
{
    sfVector2i mp = sfMouse_getPositionRenderWindow(vm->window);
    delta_time = sfClock_getElapsedTime(vm->delta_clock);
    vm->delta = delta_time.microseconds / 1000000.0;
    vm->mp = (sfVector2f){mp.x, mp.y};

    sfClock_restart(vm->delta_clock);

    double val = 180 / PI;
    int a = mp.x - 960;
    int b = mp.y - 540;
    vm->angle = atan2(b, a) * val;
}
