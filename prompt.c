#include "shell.h"

/**
 * main - Entry point
 *
 * Description: parameters passed to main
 * @void: the return from main
 *
 * Return: always 0 (Success)
 */

int main(void)
{
	char *prompt = "--Jshell  $  ";
	char *lineptr;
	size_t n = 0;
	char newline;

	while (1)
	{
		printf("%s", prompt);
		newline = getline(&lineptr, &n, stdin);
		printf("%s\n", lineptr);
		if (newline == -1)
		{
			printf("Exiting.....\n");
			return (-1);
		}
	}
	return (0);
}
