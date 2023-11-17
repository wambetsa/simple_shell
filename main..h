#ifndef MAIN_H
#define MAIN_H
#define _GNU_SOURCE

/*Include libraries section starts here*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
/*Include libraries section ends here*/

/*my function prototypes starts here*/
extern char **environ;

int _putchar(char c);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
size_t _strncmp(char *s1, char *s2, size_t n);
char *_strcat(char *dest, char *src);
char *_getpath(char **env);
char *_strcpy(char *dest, char *src);
int _path(char **arg, char **env);
void _getenv(char **env);
char *_getline(void);
char **_gettoken(char *lineptr);
void _exit_command(char **args, char *lineptr, int _exit);
char *lineptr, int np, int c);
int _forkfunction(char **arg, char **av, char **env,
char *_strtok(char *str, const char *delim);
/*my function prototypes ends here*/

#endif
/* end MAIN_H */
