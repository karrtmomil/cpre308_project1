/**
 * Karl Akert
 * this file initializes some global variables while
 * also handleing the input parameters for the shell
 */
#include "shell.h"

void initShell()
{
	prompt = "308sh> ";
	commandLen = 1024;
}

void handleArgs(int argc, char **argv)
{
	if (argc > 1)
	{
		if(strcmp(argv[1], "-p") == 0)
		{
			if(argv[2] != NULL)
				prompt = argv[2];
			else
			{
				printf("shell: Missing prompt operand\n");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			printf("shell: Invalid option: %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
	}

}
