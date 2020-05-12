/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** get_header
*/

#include <stdlib.h>
#include "asm.h"

static char *copy_line(char *str)
{
    char *cp = malloc(sizeof(char) * (my_strlen(str) + 1)); 
    int i = 0;

    for (i = 0; str[i] != '\0'; i++)
        cp[i] = str[i];
    cp[i] = '\0';
    return (cp);
}

char **get_header(char **str)
{
    char **stock;
    int i = 0;

    for (i = 0; str[i][0] == '#'; i++);
    stock = malloc(sizeof(char *) * (i + 1));
    for (int j = 0; str[j][0] == '#'; j++)
        stock[j] = copy_line(str[j]);
    stock[i] = NULL;
    return (stock);
}
