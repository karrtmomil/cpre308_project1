#include "shell.h"

void parseCommand(int *count, char ***args, char *command)
{
	
	char commandTemp[commandLen];
	strcpy(commandTemp, command);
	*count = countArgs(commandTemp);
	*args = malloc(sizeof(char*) * (*count + 1));
	char* arg;
	int i = 0;
	arg = strtok(commandTemp, " \n");
	while (arg != NULL)
	{
		(*args)[i++] = arg;
		arg = strtok(NULL, " \n");
	}
	(*args)[*count] = NULL;
}

int countArgs(char *command)
{
	int count = 0;
	while(1)
	{
		while(*command == ' ')
			command++;

		if (*command == 0 || *command == '\n')
			break;

		count++;

		while(*command != 0 && *command != ' ')
			command++;
	}
	return count;
}
