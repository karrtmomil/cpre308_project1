#include "shell.h"
#include <pthread.h>
#include <sys/wait.h>

pthread_mutex_t mutex;  

void back();

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
		printf("Cannot exec %s: No such file or directory\n", argv[0]);
		exit(EXIT_FAILURE);
	} 
	else 
	{
		/* this is the parent process */
		int pid = waitpid(ret, &status, 0);
		if (WIFEXITED(status))
		{
			printf("[%d] Exit %d\n", pid, WEXITSTATUS(status));	
		}
		else if (WIFSIGNALED(status))
		{
			printf("[%d] Killed (%d)", pid, WTERMSIG(status));
		}
	}



}

void background(int argc, char **argv)
{
	pthread_t tid_back;
	pthread_mutex_init(&mutex, NULL);
	int ret, status;
        ret = fork();
        if (ret == 0)
        {
                /* this is the child process */
                printf("[%d]\n", getpid());
                execvp(argv[0], argv);
		printf("Cannot exe %s: No Such file or directory\n", argv[0]);
                exit(EXIT_FAILURE);
        }
        else
        {
                /* this is the parent process */
                pthread_create(&tid_back, NULL, (void*)&back, NULL);
		sleep(1);
        }

}

void back()
{
	int status;
	int pid = 0;
	while(pid == 0)
	{
		pid =  waitpid(-1, &status, WNOHANG);
	}
	if (WIFEXITED(status))
        {
                printf("\n[%d] Exit %d\n", pid, WEXITSTATUS(status));
        }
        else if (WIFSIGNALED(status))
        {
                printf("\n[%d] Killed (%d)\n", pid, WTERMSIG(status));
        }
}
