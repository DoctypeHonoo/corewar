/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-hippolyte.aubert
** File description:
** connvert_hexa
*/

#include "../include/my.h"

int get_value(char c)
{
    if (c == '0') return 0;
    if (c == '1') return 1;
    if (c == '2') return 2;
    if (c == '3') return 3;
    if (c == '4') return 4;
    if (c == '5') return 5;
    if (c == '6') return 6;
    if (c == '7') return 7;
    if (c == '8') return 8;
    if (c == '9') return 9;
    if (c == 'a' || c == 'A') return 10;
    if (c == 'b' || c == 'B') return 11;
    if (c == 'c' || c == 'C') return 12;
    if (c == 'd' || c == 'D') return 13;
    if (c == 'e' || c == 'E') return 14;
    if (c == 'f' || c == 'F') return 15;
    return - 1;
}

void fill_convert(char *convert, char *str, int index, int i)
{
    int dec = 0;
    int odd_nb = my_strlen(str) % 2 == 1;

    if ((index - i) % 2 != 0) {
        dec = 16 * get_value(str[i]) + get_value(str[i + 1]);
        if (odd_nb == 1)
            convert[i / 2 + 1] = dec;
        else
            convert[i / 2] = dec;
    } else if (i == 0) {
        dec = get_value(str[0]);
        convert[0] = dec;
    }
}

char *convert_from_hexa(char *str)
{
    int len = my_strlen(str);
    int count = 0;
    int odd_nb = len % 2 == 1;
    int index = len - 1;
    char *convert = malloc(sizeof(char) * count + 1);

    if (odd_nb == 1)
        count = (len / 2) + 1;
    else
        count = len / 2;
    for (int i = index; i >= 0; i--) {
        fill_convert(convert, str, index, i);
    }
    convert[count] = '\0';
    return convert;
}
