/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** get data
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "asm.h"

static int compare_with_label_chars(char c)
{
    for (int i = 0; LABEL_CHARS[i] != '\0'; i++)
        if (c == LABEL_CHARS[i])
            return (TRUE);
    switch (c) {
    case COMMENT_CHAR :
        return (TRUE);
    case LABEL_CHAR :
        return (TRUE);
    case DIRECT_CHAR :
        return (TRUE);
    case SEPARATOR_CHAR :
        return (TRUE);
    case '\n' :
        return (TRUE);
    case ' ' :
        return (TRUE);
    }
    return (FALSE);
}

static int check_all_lines(char **split, core_t *core)
{
    for (int i = 0; split[i] != NULL; i++) {
        for (int j = 0; split[i][j] != '\0'; j++) {
            if (split[i][0] == '#' || split[i][0] == '.')
                break;
            if (compare_with_label_chars(split[i][j]))
                continue;
            else {
                my_error(core, i, STR_ERROR_CHAR);
                return (TRUE);
            }
        }
    }
    return (FALSE);
}

char **get_data(char *file, core_t *core)
{
    char **str;
    int fd = open(file, O_RDONLY);
    char buff;
    char *stock = malloc(sizeof(char) * 2);

    if (fd == -1 || stock == NULL)
        return (NULL);
    for (int i = 0; read(fd, &buff, 1) != 0; i++) {
        stock[i] = buff;
        stock[i + 1] = '\0';
        stock = realloc(stock, sizeof(char) * (my_strlen(stock) + 2));
    }
    str = my_split(stock, '\n');
    free(stock);
    if (check_all_lines(str, core))
        return (NULL);
    close(fd);
    return (str);
}
