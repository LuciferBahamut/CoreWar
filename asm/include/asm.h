/*
** EPITECH PROJECT, 2020
** corewar
** File description:
** asm.h
*/

#ifndef _ASM_H_
#define _ASM_H_

/* HELP */
int display_help(void);

/* UTIL FUNCTIONS */
void my_putchar(char c);
void my_putstr(char const *str);
int my_strlen(char *const str);
int write_error(char const *str);
int my_strcmp(char const *str1, char const *str2);

/* RETURN VALUES */
static const int ERROR = 84;
static const int SUCCESS = 0;
static const int TRUE = 1;
static const int FASLE = 0;

/* ERROR MESSAGES */
static const char ERR_ARG[] = "this program must take a file as an argument\n";

#endif /* _ASM_H_ */
