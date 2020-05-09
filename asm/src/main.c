/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** asm main
*/

#include "asm.h"

int main(int ac, char **av)
{
    if (ac != 2) {
        write_error(ERROR_ARG);
        return (write_error("\n"));
    }
    if (my_strcmp(av[1], "-h"))
        return (display_help());
    return (SUCCESS);
}
