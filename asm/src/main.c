/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** asm main
*/

#include <stdlib.h>
#include <unistd.h>
#include "asm.h"

int fill_core(core_t *core, char *file)
{
    if ((core->name = get_name(file)) == NULL)
        return (TRUE);
    core->data = get_data(file);
    return (FALSE);
}

int start(char *file)
{
    core_t *core = malloc(sizeof(core_t));

    if (core == NULL || fill_core(core, file))
        return (ERROR);
    return (SUCCESS);
}

int main(int ac, char **av)
{
    if (ac != 2) {
        write_error(ERROR_ARG);
        return (write_error("\n"));
    }
    if (my_strcmp(av[1], "-h"))
        return (display_help());
    else
        return (start(av[1]));
}
