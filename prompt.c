#include "shell.h"

/**
 * main - Entry point
 *
 * Description: parameters passed to main
 * @void: the return from main
 *
 * Return: always 0 (Successi)
 */

int main(void)
{
	char *prompt = "--Jshell  $  ";
	char *lineptr, *lineptr_cpy = NULL;
	size_t n = 0;
	ssize_t newline;
	char *delim = " \n";
	char *token;
	int num_token = 0;
	int i;
	char **argv;

	while (1)
	{
		printf("%s", prompt);
		newline = getline(&lineptr, &n, stdin);
		if (newline == -1)
		{
			printf("Exiting.....\n");
			return (-1);
			break;
		}
		lineptr_cpy = malloc(sizeof(char) * newline);
		strcpy(lineptr_cpy, lineptr);
		token = strtok(lineptr, delim);
		while (token != NULL)
		{
			num_token++;
			token = strtok(NULL, delim);
		}
		num_token++;
		argv = malloc(sizeof(char *) * num_token);
		token = strtok(lineptr_cpy, delim);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
		execmd(argv);
		free(argv);
		free(lineptr_cpy);
		free(lineptr);
	}
	return (0);
}
