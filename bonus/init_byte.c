/*
** EPITECH PROJECT, 2022
** graphique
** File description:
** init_byte
*/

#include "../include/op.h"
#include "../include/my.h"

void finalize_byte(bytes_t byte, char *code, sfVector2f pos1)
{
    sfVector2f pos2 = (sfVector2f) {pos1.x + 5, pos1.y + 5};
    sfVector2f scale2 = (sfVector2f) {15, 15};

    sfRectangleShape_setSize(byte.carre, byte.scale);
    sfRectangleShape_setSize(byte.carre2, scale2);
    sfRectangleShape_setPosition(byte.carre, byte.pos);
    sfRectangleShape_setPosition(byte.carre2, pos2);
    sfRectangleShape_setFillColor(byte.carre, (sfColor) {64, 64, 64, 255});
    sfRectangleShape_setFillColor(byte.carre2, sfBlack);
    sfText_setFont(byte.text, byte.font);
    sfText_setPosition(byte.text, (sfVector2f) {pos2.x + 2, pos2.y - 1});
    sfText_setCharacterSize(byte.text, 12);
    sfText_setColor(byte.text, (sfColor) {139, 142, 142, 255});
    sfText_setString(byte.text, code);
}

bytes_t init_byte(char *code, sfVector2f pos1)
{
    bytes_t byte = {0};

    byte.pos = pos1;
    byte.scale = (sfVector2f) {20, 20};
    byte.carre = sfRectangleShape_create();
    byte.carre2 = sfRectangleShape_create();
    byte.text = sfText_create();
    byte.font = sfFont_createFromFile("./bonus/assets/font.ttf");
    finalize_byte(byte, code, pos1);
    return byte;
}

int get_total_size(champgph_t *champs, int nb)
{
    int i = 0;

    for (int j = 0; j < nb; j++)
        i += champs[j].size;
    return i;
}

void put_champ(champgph_t *champs, bytes_t *bytes, int nb)
{
    int x = 0;
    sfBool B = sfFalse;
    sfColor TC = sfBlue;

    for (int i = 0; i < nb; i++) {
        for (int j = 0; j < champs[i].size; j++) {
            if (i > 0 && !B) {
                x = (MEM_SIZE / 2);
                B = sfTrue;
                TC.b = 0;
                TC.r = 255;
            }
            sfText_setString(bytes[x].text, champs[i].champion[j]);
            sfText_setColor(bytes[x].text, TC);
            x++;
        }
    }
}

bytes_t *init_bytes_tab(champgph_t *champs, int nb)
{
    bytes_t *bytes = malloc(sizeof(bytes_t) * MEM_SIZE);
    sfVector2f pos = (sfVector2f) {0, 0};

    for (int i = 0; i < MEM_SIZE; i++) {
        bytes[i] = init_byte("00", pos);
        pos.x += 20;
        if (pos.x == 1920) {
            pos.x = 0;
            pos.y += 20;
        }
    }
    put_champ(champs, bytes, nb);
    return bytes;
}
