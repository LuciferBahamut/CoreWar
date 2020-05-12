/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** get_champ
*/

#include <stdlib.h>
#include "asm.h"

static void my_error(core_t *core, int i)
{
    write_error("asm, ");
    write_error(core->file);
    write_error(", line ");
    my_put_nbr_error(i);
    write_error(": The program name is too long.\n");
}

static int my_spe_cmp(char *str)
{
    int i = 0;

    for (i = 0; str[i] != ' '; i++);
    if (i != my_strlen(NAME_CMD_STRING))
        return (FALSE);
    for (int j = 0; NAME_CMD_STRING[j] != '\0'; j++)
        if (str[j] != NAME_CMD_STRING[j])
            return (FALSE);
    return (TRUE);
}

static int check_pos_name(char **str)
{
    int i = 0;

    for (; str[i][0] != '.'; i++);
    for (; my_spe_cmp(str[i]) != TRUE; i++);
    return (i);
}

int get_champ(core_t *core)
{
    int i = check_pos_name(core->data);
    int k = 0;
    char *name;

    name = malloc(sizeof(char) * my_strlen(core->data[i]));
    for (int j = 6; core->data[i][j] != '\0'; j++, k++)
        name[k] = core->data[i][j];
    name[k] = '\0';
    if ((my_strlen(name) - 2) > PROG_NAME_LENGTH) {
        my_error(core, i);
        return (TRUE);
    }
    else
        for (int j = 0; name[i] != '\0'; i++)
            core->head->prog_name[j] = name[j];
    free(name);
    return (FALSE);
}
