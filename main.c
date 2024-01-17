#include "monty.h"
/* global variable */
vars var = {NULL, NULL, NULL, 0};

/**
 * main - entry point to the program
 * @argc: argument counter
 * @argv: array of arguments
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	FILE *file;
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t characters;
	bool file_not_empty = true;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	var.file = file;
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (file_not_empty)
	{
		buffer = NULL;
		characters = getline(&buffer, &bufsize, file);
		var.data = buffer;
		counter++;
		if (characters > 0)
			execute(&stack, counter, file, buffer);
		free(buffer);
	}
	stack_free(stack);
	fclose(file);
	return (0);
}
