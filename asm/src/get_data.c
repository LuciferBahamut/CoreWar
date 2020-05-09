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

char **get_data(char *file)
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
    close(fd);
    return (str);
}
