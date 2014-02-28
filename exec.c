#include "shell.h"
#include <pthread.h>

pthread_mutex_t mutex;  

void execf();

int count;
char **args;


void foreground(int argc, char **argv)
{
	pthread_t tid_foreground;

	pthread_mutex_init(&mutex, NULL);	
	count = argc;
	args = argv;
	printf("parent?: %d\n", getpid());
	pthread_create(&tid_foreground, NULL, (void*)&execf, NULL);

	pthread_join(tid_foreground, NULL);



}

void background(int argc, char **argv)
{

}

void execf()
{
	printf("Run exec here: %d\n", getpid());
}