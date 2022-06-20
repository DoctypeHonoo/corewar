/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-hippolyte.aubert
** File description:
** op
*/

#ifndef OP_H_
    #define OP_H_
    #define T_REG 1
    #define T_DIR 2
    #define T_IND 4
    #define T_LAB 8
    #define IND_SIZE 2
    #define DIR_SIZE 4
    #define REG_SIZE DIR_SIZE
    #define COREWAR_EXEC_MAGIC 0xea83f3
    #define PROG_NAME_LENGTH 128
    #define COMMENT_LENGTH 2048
    #define CYCLE_TO_DIE 1536
    #define CYCLE_DELTA 5
    #define NBR_LIVE 40
    #define MEM_SIZE (6 * 1024)
    #define IDX_MOD 512
    #define MAX_ARGS_NUMBER 4
    #define COMMENT_CHAR '#'
    #define LABEL_CHAR ':'
    #define DIRECT_CHAR '%'
    #define SEPARATOR_CHAR ','
    #define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"
    #define NAME_CMD_STRING ".name"
    #define COMMENT_CMD_STRING ".comment"
    #define REG_NUMBER 16
    #define REV(x) ((x & 0x000000FF) << 24) | ((x & 0x0000FF00) << 8) |\
    ((x & 0x00FF0000) >> 8) | ((x & 0xFF000000) >> 24)
    #define PI 3.14159265
    #include <fcntl.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics/Export.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Transform.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/System/Vector2.h>
    #include <stdlib.h>
    #include <math.h>
    #include <stddef.h>

typedef struct header_s {
    int magic;
    char prog_name[PROG_NAME_LENGTH + 1];
    int prog_size;
    char comment[COMMENT_LENGTH + 1];
} header_t;

typedef struct op_s {
    char *mnemonique;
    char nbr_args;
    char type[MAX_ARGS_NUMBER];
    char code;
    int nbr_cycles;
    char *comment;
} op_t;
extern op_t op_tab[];

typedef struct bytes_s {
    sfSprite *sprite;
    sfRectangleShape *carre, *carre2;
    sfVector2f pos, scale;
    sfText *text;
    sfFont *font;
} bytes_t;

typedef struct cw_s {
    sfRenderWindow *window;
    bytes_t *bytes;
    sfEvent event;
    sfClock *delta_clock;
    float delta;
    double angle;
    sfVector2f mp;
} cw_t;

typedef struct champgph_s {
    char **champion;
    int size;
} champgph_t;

#endif
