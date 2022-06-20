/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-hippolyte.aubert
** File description:
** convert_to_binary
*/

#include "../include/my.h"

void convert_to_hex(int nb, char *str, int index)
{
    char *base = "0123456789ABCDEF";

    if (nb > 16) {
        convert_to_hex(nb / 16, str, index);
        index++;
    }
    str[index] = base[nb % 16];
}

char *convert_to_binary(char *str)
{
    int nb = my_atoi(str);
    char *bi = malloc(sizeof(char) * nb * my_strlen(str));
    int q = nb;

    for (int i = 0; q > 0; i++) {
        bi[i] = (q % 2) + '0';
        q /= 2;
    }
    bi = reverse_str(bi);
    return bi;
}

char *two_complement_convert(char *str)
{
    str = convert_to_binary(str);
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == '0')
            str[i] = '1';
        else if (str[i] == '1')
            str[i] = '0';
    }
    return str;
}

// char *decimal_to_hex(char *str)
// {
//     int nb = my_atoi(str);
//     char *hex = malloc(sizeof(char) * nb * my_strlen(str));
//     int q = nb;

//     for (int i = 0; q > 0; i++) {
//         hex[i] = get_hex_value(q % 16);
//         q /= 16;
//     }
//     return hex;
// }

char decimal_to_hex(int nb)
{
    int q = nb;
    int r = 0;
    char hex[100];
    int i = 0;

    while (q > 0) {
        r = q % 16;
        if (r < 10)
            hex[i++] = 48 + r;
        else
            hex[i++] = 55 + r;
        q /= 16;
    }
    return hex[i];
}
