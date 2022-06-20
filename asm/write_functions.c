/*
** EPITECH PROJECT, 2022
** B-CPE-201-MPL-2-1-corewar-hippolyte.aubert
** File description:
** write_functions
*/

#include "../include/my.h"

char **get_code_size_2(clean_t *cleaned, char **str, int i)
{
    int k = 0;

    if (is_label(str[0])) {
        for (; cleaned->code[i][k] != ':'; k++);
        if (remake_clean(cleaned, i, k) != NULL)
            return my_strtok(remake_clean(cleaned, i, k), " ,");
        else
            return NULL;
    }
    return str;
}

int get_code_size(clean_t *cleaned)
{
    int i = 0;
    int j = 0;
    char **line = NULL;
    uint32_t size = 0;

    for (; cleaned->code[i]; i++) {
        line = my_strtok(cleaned->code[i], " ,");
        if (get_code_size_2(cleaned, line, i) == NULL)
            continue;
        else
            line = get_code_size_2(cleaned, line, i);
        for (j = 0; op_tab[j].mnemonique; j++) {
            size += parse_line(line, j);
        }
    }
    return size;
}

char get_int(char *str)
{
    int i = 0;

    for (; my_strcmp(op_tab[i].mnemonique, str) != 0; i++);
    return op_tab[i].code;
}
/*
int push_code_2(clean_t **cleaned, char *new_name)
{
    for (int j = 1; line[j]; j++) {
            if (is_index(line, j)) {
                writing = atoi(get_part(line[j], 1, my_strlen(line[j])));
                write(fd, &writing, 2);
                continue;
            }
            if (is_register(line[j])) {
                writing = atoi(get_part(line[j], 1, my_strlen(line[j])));
                write(fd, &writing, 1);
                continue;
            }
            if (is_dir(line[j])) {
                writing = atoi(get_part(line[j], 1, my_strlen(line[j])));
                write(fd, &writing, 4);
                continue;
            }
            if (is_ind(line[i])) {
                writing = 15;
                write(fd, &writing, 2);
                continue;
            }
        }
}
*/
int push_code(clean_t *cleaned, char *new_name)
{
    int i = 0;
    char **line = NULL;
    int writing = 0;
    int fd = open(new_name, O_RDWR | O_APPEND);

    for (; cleaned->code[i]; i++) {
        line = my_strtok(cleaned->code[i], " ,");
        if (get_code_size_2(cleaned, line, i) == NULL)
            continue;
        else
            line = get_code_size_2(cleaned, line, i);
        writing = get_int(line[0]);
        write(fd, &writing, 1);
        if (need_pcb(line[0])) {
            writing = 104;
            write(fd, &writing, 1);
        }
        for (int j = 1; line[j]; j++) {
            if (is_index(line, j)) {
                writing = 0;
                write(fd, &writing, 1);
                writing = atoi(get_part(line[j], 1, my_strlen(line[j])));
                write(fd, &writing, 1);
                continue;
            }
            if (is_register(line[j])) {
                writing = atoi(get_part(line[j], 1, my_strlen(line[j])));
                write(fd, &writing, 1);
                continue;
            }
            if (is_dir(line[j])) {
                writing = atoi(get_part(line[j], 1, my_strlen(line[j])));
                write(fd, &writing, 4);
                continue;
            }
            if (is_ind(line[i])) {
                writing = 15;
                write(fd, &writing, 2);
                continue;
            }
        }
    }
    return 0;
}

int push_comment(clean_t *cleaned, char *new_name)
{
    int i = 0;
    char comment[COMMENT_LENGTH - 12];
    int fd = open(new_name, O_RDWR | O_APPEND);
    int size = get_code_size(cleaned);

    write(fd, &size, 1);
    for (; cleaned->comment[i] != '\0'; i++)
        comment[i] = cleaned->comment[i];
    for (; i != COMMENT_LENGTH - 12; i++)
        comment[i] = 0;
    write (fd, comment, sizeof(comment));
    close(fd);
    return push_code(cleaned, new_name);
}

int push_file(clean_t *cleaned, char *path)
{
    int i = 0;
    int k = 0;
    char name[PROG_NAME_LENGTH + 7];
    int magic = REV(COREWAR_EXEC_MAGIC);
    int fd = 0;
    char *new_name = NULL;

    for (; path[i] != '.'; i++);
    new_name = my_strcat(get_part(path, 0, i), ".cor");
    fd = open(new_name, O_CREAT | O_RDWR, 0644);
    write (fd, &magic, sizeof(magic));
    for (; cleaned->name[k] != '\0'; k++)
        name[k] = cleaned->name[k];
    for (; k != PROG_NAME_LENGTH + 7; k++)
        name[k] = 0;
    write(fd, name, sizeof(name));
    close(fd);
    return push_comment(cleaned, new_name);
}
