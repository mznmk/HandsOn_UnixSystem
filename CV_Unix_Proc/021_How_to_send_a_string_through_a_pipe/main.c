#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int	main(int argc, char **argv)
{
	int pfd[2];
	if (pipe(pfd) == -1)
		return (1);

	int pid = fork();
	if (pid < 0)
		return (2);
	if (pid == 0)
	{
		// Child process
		close(pfd[0]);
		char str[200];
		printf("Input string: ");
		fgets(str, 200, stdin);
		str[strlen(str) - 1] = '\0';
		int n = strlen(str) + 1;
		if (write(pfd[1], &n, sizeof(int)) < 0)
			return (3);
		if (write(pfd[1], str, sizeof(char) * n) < 0)
			return (4);
		close(pfd[1]);
	}
	else
	{
		// Parent process
		close(pfd[1]);
		char str[200];
		int n;
		if (read(pfd[0], &n ,sizeof(int)) < 0)
			return (5);
		if (read(pfd[0], str, sizeof(char) * n) < 0)
			return (6);
		printf("Received: %s\n", str);
		close(pfd[0]);
		wait(NULL);
	}

	return (0);
}
