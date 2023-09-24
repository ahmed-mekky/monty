#include "monty.h"
#define DELIM " "
#define BUFSIZE 128
/**
 * main - main monty function
 * @av: .....
 * @ac: ..
 *
 * Return: 0.
 */
int main(int ac, char **av)
{
	char *filename = av[1];
	int line_num = 0;
	size_t len = 0;
	char *line = NULL, **words;
	ssize_t nread;
	FILE *fd;

	if (ac != 2)
	{
		fprintf(stderr ,"USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(filename, "r");
	if (!fd)
	{
		fprintf(stderr ,"Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while((nread = getline(&line, &len, fd)) != -1)
	{
		line_num++;
		words = split_line(line);
		instruction_t ops[] = {
				{"push", f_push},
				{"pall", f_pall},
				{"pop", f_pop},
				{"swap", f_swap},
				{"add", f_add},
				{NULL, NULL}
				};
	}
	return (0);
}
char **split_line(char *line)
{
	int bufsize = BUFSIZE, i = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "): allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, DELIM);
	while (token != NULL)
	{
		tokens[i++] = token;

		if (i >= bufsize)
		{
			bufsize += BUFSIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "): allocation error\n");
				exit(EXIT_FAILURE);
			}
		}

		token = strtok(NULL, DELIM);
	}
	tokens[i] = NULL;
	return (tokens);
}
