#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char *prompt;
extern int commandLen;

void initShell();
void handleArgs(int argc, char **argv);
void parseCommand(int *count, char ***args, char *command);
int countArgs(char *command);
void handleCommand(int argc, char **argv);
void bExit();
int pid();
int ppid();
void cd(const char *path);
char *pwd();
// void set(char *env, char *value, int set);
char *get(char *env);

#endif