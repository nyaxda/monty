#include "monty.h"
vars var = {NULL, NULL, NULL, 0};
/**
 * main - entry point to the program
 * @argc: arguement counter
 * @argv: array of arguements
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
	if ((file = fopen(argv[1], "r")) == NULL)
	{
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
	}
	while (file_not_empty)
	{
		if ((characters = getline(&buffer, &bufsize, file)) == -1)
				break;
		var.data = buffer;
		counter++;
		execute(&stack, counter, file, buffer);
		free(buffer);
		buffer = NULL;
	}
	stack_free(stack);
	if (buffer != NULL)
		free(buffer);
	fclose(file);
	return (0);
}
