#include "shell.h"

char* prompt;
int commandLen;

int main(int argc, char **argv)
{
	initShell();
	handleArgs(argc, argv);
	char command[commandLen];
	while(1)
	{
		printf("%s", prompt);
		if (fgets(command, commandLen, stdin) != NULL)
		{
			int count;
			char **args;
			parseCommand(&count, &args, command);
			handleCommand(count, args);
		}
		else
		{
			printf("Error with stdin\n");
		}
	}
}

void parseCommand(int *count, char ***args, char* command)
{
	
	char commandTemp[commandLen];
	strcpy(commandTemp, command);
	*count = countArgs(commandTemp);
	*args = malloc(sizeof(char*) * *count);
	char* arg;
	int i = 0;
	arg = strtok(commandTemp, " \n");
	while (arg != NULL)
	{
		(*args)[i++] = arg;
		arg = strtok(NULL, " \n");
	}
}

int countArgs(char* command)
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

void handleCommand(int argc, char **argv)
{
	int i;
	for(i=0; i<argc; i++)
	{
		printf("Option %d is \"%s\"\n", i, argv[i]);
	}
}
