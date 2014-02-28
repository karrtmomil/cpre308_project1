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

void handleCommand(int argc, char **argv)
{
	int i;
	for(i=0; i<argc; i++)
	{
		printf("Option %d is \"%s\"\n", i, argv[i]);
	}
}
