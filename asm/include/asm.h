/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** asm.h
*/

#ifndef _ASM_H_
#define _ASM_H_

#include "op.h"

#define SWAP_UINT32(x) ((x >> 24) & 0xff) | (( x << 8) & 0xff0000) |\
    ((x >> 8) & 0xff00) | ((x << 24) & 0xff000000)

typedef struct core_s
{
    char *file;
    char *name;
    char **data;
    header_t *head;
    int error_line;
} core_t;

/* HELP */
int display_help(void);

/* FILL CORE */
char *get_name(char *file);
char **get_data(char *file, core_t *core);
int get_champ(core_t *core);
int get_comment(core_t *core);

/* ERROR HANDLING */
int check_prog(core_t *core);
int check_instruction(char *instr, int nbr);

/* UTIL FUNCTIONS */
void my_putchar(char c);
void my_putchar_error(char c);
void my_putstr(char const *str);
int my_strlen(char *const str);
int write_error(char const *str);
int my_strcmp(char const *str1, char const *str2);
int my_put_nbr_error(int nb);
int my_put_nbr(int nb);

/* DISPLAY ERROR */
void my_error(core_t *core, int i, const char *error);

/* RETURN VALUES */
static const int ERROR = 84;
static const int SUCCESS = 0;
static const int TRUE = 1;
static const int FALSE = 0;

/* ERROR MESSAGES */
// args
static const char ERROR_ARG[] = "this program must take a file as an argument";

// undefined char
static const char STR_ERROR_CHAR[] = ": Undefined label.\n";
static const char STR_ERROR_INST[] = ": Invalid instruction.\n";

// name
static const char STR_ERROR_NAME[] = ": The program name is too long.\n";
static const char STR_ERROR_NONAME[] = ": No name specified.\n";

// comment
static const char STR_WAR_NOCOMMENT[] = ": Warning : No comment specified.\n";
static const char STR_ERROR_TOOLONGCOM[] = ": The comment is too long.\n";

#endif /* _ASM_H_ */
