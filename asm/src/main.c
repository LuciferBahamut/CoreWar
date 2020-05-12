/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** asm main
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "asm.h"

static int check_file(char *file)
{
    int fd = open(file, O_RDONLY);

    if (fd == -1)
        return (TRUE);
    close(fd);
    return (FALSE);
}

static int fill_core(core_t *core, char *file)
{
    if (check_file(file) || (core->name = get_name(file)) == NULL)
        return (TRUE);
    core->data = get_data(file);
    core->header = get_header(core->data);
    core->champ = get_champ(core->data);
    return (FALSE);
}

static int start(char *file)
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
