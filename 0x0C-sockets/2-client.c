#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <netdb.h>

#define USAGE "Usage: %s <host> <port>\n"

/**
 * main - socket client
 * @argc: argument vector
 * @argv: argument count
 * Return: SUCCESS or FAILURE
 */
int main(int argc, char **argv)
{
	struct sockaddr_in server;
	struct hostent *host;
	int sd = 0;

	if (argc != 3)
		return (printf(USAGE, argv[0]), EXIT_FAILURE);

	host = gethostbyname(argv[1]);
	sd = socket(PF_INET, SOCK_STREAM, 0);

	if (sd < 0)
	{
		perror("socket failed");
		return (EXIT_FAILURE);
	}

	server.sin_family = AF_INET;
	inet_pton(AF_INET, inet_ntoa(*(struct in_addr *)host->h_addr),
		&server.sin_addr);
	server.sin_port = htons(atoi(argv[2]));

	if (connect(sd, (struct sockaddr *)&server, sizeof(server)) < 0)
	{
		perror("connect failure");
		return (EXIT_FAILURE);
	}

	printf("Connected to %s:%s\n", argv[1], argv[2]);
	close(sd);

	return (EXIT_SUCCESS);
}
