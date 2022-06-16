#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void	main()
{
	int		status;
	int		a, b, c;

	if (fork())
	{
		// Parent

		wait (&status);
		if (WIFEXITED(status))
			printf("Child exited normally with exit status %d\n", WEXITSTATUS(status));
		if (WIFSIGNALED(status))
			printf("Child exited on signal %d: %s\n", WTERMSIG(status), strsignal(WTERMSIG(status)));
	}
	else
	{
		// Child

		// printf("Child PID = %d\n", getpid());
		// sleep(3);
		// exit(5);

		// printf("Child PID = %d\n", getpid());
		// *(int *)0 = 99;
		// sleep(3);
		// exit(5);

		// printf("Child PID = %d\n", getpid());
		// a = 1;
		// b = 0;
		// c = a / b;
		// sleep(3);
		// exit(5);

		printf("Child PID = %d\n", getpid());
		pause();
		exit(5);
	}
}