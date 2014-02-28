#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initShell();
void handleArgs(int argc, char **argv);
void parseCommand(int *count, char ***args, char* command);
int countArgs(char* command);
void handleCommand(int argc, char **argv);

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

void initShell()
{
	prompt = "308sh> ";
	commandLen = 256;
}

void handleArgs(int argc, char **argv)
{
	if (argc > 1)
	{
		if(strcmp(argv[1], "-p") == 0)
		{
			if(argv[2] != NULL)
				prompt = argv[2];
		}
		else
		{
			printf("Unknown option: %s\n", argv[1]);
			exit(EXIT_FAILURE);
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
