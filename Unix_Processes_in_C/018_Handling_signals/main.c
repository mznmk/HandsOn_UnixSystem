#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void 	handle_sigtstp(int sig)
{
	printf("Stop not allowed\n");
}

void 	handle_sigcont(int sig)
{
	printf("Input number: ");
	fflush(stdout);
}

int main(int argc, char **argv)
{
	// struct sigaction sa;
	// sa.sa_handler = &handle_sigtstp;
	// sa.sa_flags = SA_RESTART;
	// sigaction(SIGTSTP, &sa, NULL);

	// signal(SIGTSTP, &handle_sigtstp);

	struct sigaction sa;
	sa.sa_handler = &handle_sigcont;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGCONT, &sa, NULL);

	int x;
	printf("input number: ");
	scanf("%d", &x);
	printf("Result %d * 5 = %d\n", x, x * 5);

	return (0);
}
