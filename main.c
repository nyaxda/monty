#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

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
                if (*buffer == '\n')
                {
                        free(buffer);
                        buffer = NULL;
                        continue;
                }
        }
        free(buffer);
        fclose(file);
        exit(EXIT_SUCCESS);
}
