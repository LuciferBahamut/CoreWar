/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** get_champ
*/

#include <stdlib.h>
#include "asm.h"

char *get_champ(char **str)
{
    int i = 0;
    int k = 0;
    char *name;

    for (; str[i][0] == '#'; i++);
    if (str[i][0] != '.')
        i++;
    name = malloc(sizeof(char) * my_strlen(str[i]));
    for (int j = 6; str[i][j] != '\0'; j++, k++)
        name[k] = str[i][j];
    name[k] = '\0';
    return (name);
}
