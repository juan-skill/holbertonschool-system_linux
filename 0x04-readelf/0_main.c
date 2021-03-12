#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * main - Entry point
 *
 * @argc: number of arguments of array
 * @argv: array of arguments
 *
 * Return: Always (0)
 */
int main(int argc, char **argv)
{
        extern char **environ;
        char *array_command[] = {"/usr/bin/readelf", "-W", "-h", "", NULL};
        (void)argc;

        array_command[3] = argv[1];
        if (execve("/usr/bin/readelf", array_command, environ) == -1)
        {
                perror("execve");
                return (EXIT_FAILURE);
        }

        return (EXIT_SUCCESS);
}
