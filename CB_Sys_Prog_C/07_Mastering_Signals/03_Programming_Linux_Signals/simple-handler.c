/* Simple signal demo */

#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>

int	n;

void	handler(int signum)
{
	printf("signal %d received - counter reset\n", signum);
	n = 0;
}
void	main()
{
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTERM, SIG_IGN);
	while (1)
	{
		printf("Working %d\n", n++);
		sleep(1);
	}
}
