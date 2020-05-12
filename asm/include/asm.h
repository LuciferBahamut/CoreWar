/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** asm.h
*/

#ifndef _ASM_H_
#define _ASM_H_

typedef struct core_s
{
    char *name;
    char **data;
    char **header;
    char *champ;
} core_t;

/* HELP */
int display_help(void);

/* FILL CORE */
char *get_name(char *file);
char **get_data(char *file);
char *get_champ(char **str);
char **get_header(char **str);

/* UTIL FUNCTIONS */
void my_putchar(char c);
void my_putstr(char const *str);
int my_strlen(char *const str);
int write_error(char const *str);
int my_strcmp(char const *str1, char const *str2);
char **my_split(char *src, char c);

/* RETURN VALUES */
static const int ERROR = 84;
static const int SUCCESS = 0;
static const int TRUE = 1;
static const int FALSE = 0;

/* ERROR MESSAGES */
static const char ERROR_ARG[] = "this program must take a file as an argument";

#endif /* _ASM_H_ */
