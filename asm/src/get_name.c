/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** get name
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "asm.h"

char *get_name(char *file)
{
    int fd = open(file, O_RDONLY);
    char *name;
    int i = 0;

    if (fd == -1)
        return (NULL);
    if ((name = malloc(sizeof(char) * (my_strlen(file) + 4))) == NULL)
        return (NULL);
    for (i = 0; file[i] != '\0'; i++)
        if (file[i] == '.')
            break;
        else
            name[i] = file[i];
    name[i] = '.';
    name[i + 1] = 'c';
    name[i + 2] = 'o';
    name[i + 3] = 'r';
    name[i + 4] = '\0';
    close(fd);
    return (name);
}
