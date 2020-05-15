/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** get_champ
*/

#include <stdlib.h>
#include "asm.h"

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

    if (str[i] == NULL)
        return (-1);
    for (; str[i][0] != '.'; i++) {
        if (str[i + 1] == NULL)
            return (-2);
    }
    for (; my_spe_cmp(str[i]) != TRUE; i++);
    return (i);
}

static int display_errors(core_t *core, int i)
{
    if (i == -1)
        my_error(core, 1, STR_ERROR_INST);
    else
        my_error(core, 1, STR_ERROR_NONAME);
    return (TRUE);
}

int get_champ(core_t *core)
{
    int i = check_pos_name(core->data);
    int k = 0;
    char *name;

    if (i < 0)
        return (display_errors(core, i));
    name = malloc(sizeof(char) * my_strlen(core->data[i]));
    for (int j = 6; core->data[i][j] != '\0'; j++, k++)
        name[k] = core->data[i][j];
    name[k] = '\0';
    if ((my_strlen(name) - 2) > PROG_NAME_LENGTH) {
        my_error(core, i, STR_ERROR_NAME);
        return (TRUE);
    }
    else
        for (int j = 0; name[i] != '\0'; i++)
            core->head->prog_name[j] = name[j];
    free(name);
    return (FALSE);
}
