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

static int check_file(char *file, core_t *core)
{
    int fd = open(file, O_RDONLY);
    int i = 0;

    if (fd == -1)
        return (TRUE);
    close(fd);
    core->file = malloc(sizeof(char) * (my_strlen(file) + 1));
    if (core->file == NULL)
        return (FALSE);
    for (i = 0; file[i] != '\0'; i++)
        core->file[i] = file[i];
    core->file[i] = '\0';
    return (FALSE);
}

static int fill_core(core_t *core, char *file)
{
    if (check_file(file, core) || (core->name = get_name(file)) == NULL)
        return (TRUE);
    core->data = get_data(file);
    if (get_champ(core))
        return (TRUE);
    return (FALSE);
}

static int start(char *file)
{
    core_t *core = malloc(sizeof(core_t));

    if (core == NULL)
        return (ERROR);
    core->head = malloc(sizeof(header_t));
    if (core->head == NULL)
        return (ERROR);
    if (fill_core(core, file))
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
