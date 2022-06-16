#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int	main(int argc, char **argv)
{
	int pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		while (1)
		{
			printf("Some text goes here\n");
			sleep(1);	
		}
	}
	else
	{
		sleep(3);
		kill(pid, SIGKILL);
		wait(NULL);
	}

	return (0);
}
