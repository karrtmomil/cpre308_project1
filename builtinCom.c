#include "shell.h"

void bExit()
{
	exit(EXIT_SUCCESS);
}

int pid()
{
	return getpid();
}

int ppid()
{
	return getppid();
}

void cd(const char *path)
{
	if (chdir(path) < 0)
	{
		printf("shell: cd: %s: No such file or directory\n", path);
	}
}

char *pwd()
{
	char *path = (char *)get_current_dir_name();
	return path;
}

// void set(char *env, char *value, int set)
// {
// 	printf("%s not %s\n", env, value);
// 	if (set)
// 	{
// 		printf("%s here %s\n", env, value);
// 		setenv(env, value, 1);
// 	}
// 	else
// 	{
// 		printf("Here\n");
// 		unsetenv(env);
// 	}
// }

char *get(char *env)
{
	return getenv(env);
}