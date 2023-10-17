#include "shell.h"

/**
 * execmd - executing strings in argv
 *
 * @argv: the string to be executed
 *
 * Return: always 0 (success)
 */

void execmd(char **argv)
{
	char *command = NULL;
	__pid_t pid;

	pid = fork();
	if (pid == 0)
	{
		if (argv)
		{
			command = argv[0];

			if (execve(command, argv, NULL) == -1)
			{
				perror("Error:");
				exit(EXIT_FAILURE);
			}
		}
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);
	}
}
