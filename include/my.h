/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-hippolyte.aubert
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #include "op.h"
    //#include "../lib/my/op.c"
    #define UNUSED() __attribute__((unused))
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <stdbool.h>
    #include <string.h>
    #include <sys/types.h>
    #include <stdint.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <fcntl.h>

    #define S_LEN(str) my_strlen(str)

typedef struct champ_s {
    int id;
    int lives;
    char *name;
    char *ins;
} champ_t;

typedef struct vm_s {
    char *arena;
    int nb_champ;
    champ_t *champ;
} vm_t;

typedef struct s_clean {
    char *name;
    char *comment;
    char **code;
} clean_t;

int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
char *my_strdup(char const *src);
char **my_strtok(char *str, char *separators);
int is_register(char *str);
uint32_t parse_line(char **line, int j);
uint32_t get_parameters(char **line);
int need_pcb(char *name);
clean_t *clean_map(char **file, char *path);
int clean_map_2(char *map, int pos, clean_t *cleaned);
clean_t *handle_errors(clean_t *cleaned);
char *remake_clean(clean_t *cleaned, int i, int dots);
int check_if_next(char *str, int dots);
char *get_part(char *str, int start, int end);
int is_dir(char *str);
int is_label(char *str);
int is_ind(char *str);
int is_index(char **line, int i);
int push_file(clean_t *cleaned, char *path);
int push_comment(clean_t *cleaned, char *new_name);
int get_code_size(clean_t *cleaned);
char *concat_array(char **array);
int is_in_str(char *str, char *tf);
char *my_strcat(char *dest, char *src);
int my_printf(const char *format, ...);
char *convert_from_hexa(char *str);
char get_hex_value(int nb);
void print_hexa(char *filename);
char *get_champ_name(char *filename);
char *get_champ_instructions(char *filename);
char *my_itoa(int nb);
int my_atoi(char *str);
char *convert_to_binary(char *str);
char *reverse_str(char *str);
char *two_complement_convert(char *str);
void convert_to_hex(int nb, char *str, int index);
champ_t init_champ(char *filename, int nb);
char *create_arena(champ_t *champ, char **argv);
int count_champs(char **argv);
char **get_champ_files(char **argv);

/* VM */

void delta_time(cw_t *vm, sfTime delta_time);
void process_game(champgph_t *champs, int nb);
sfRenderWindow *init_window(int w, int h, char *title);
bytes_t *init_bytes_tab(champgph_t *champs, int nb);
char *read_file(char *filepath);
char **line_to_array(char *arg);
champgph_t *init_all_champs(int ac, char **av);
char *my_strcpy(char *dest, char *src);

#endif
