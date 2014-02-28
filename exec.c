#include "shell.h"
#include <pthread.h>
#include <sys/wait.h>

pthread_mutex_t mutex;  

void execf();

int count;
char **args;


void foreground(int argc, char **argv)
{
/*
	pthread_t tid_foreground;

	pthread_mutex_init(&mutex, NULL);	
	count = argc;
	args = argv;
	printf("parent?: %d\n", getpid());
	pthread_create(&tid_foreground, NULL, (void*)&execf, NULL);

	pthread_join(tid_foreground, NULL);
*/
	int ret, status;
	ret = fork();
	if (ret == 0) 
	{
		/* this is the child process */
		printf("[%d]\n", getpid());
		execvp(argv[0], argv);
		exit(EXIT_SUCCESS);
	} 
	else 
	{
		/* this is the parent process */
		printf("[%d]\n",waitpid(ret, &status, 0));
	}



}

void background(int argc, char **argv)
{

}

void execf()
{
	printf("Run exec here: %d\n", getpid());
}
