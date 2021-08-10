#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>



int	main(int argc, char **argv)
{
	int	pid1 = fork();
	if (pid1 < 0){
		printf("Error creating process");
		return (1);
	}
	else if (pid1 == 0)
	{
		// Child process 1
		sleep(4);
		printf("finished execution (%d)\n", getpid());
		return (0);
	}

	int	pid2 = fork();
	if (pid2 < 0){
		printf("Error creating process");
		return (1);
	}
	else if (pid2 == 0)
	{
		// Child process 2
		sleep(1);
		printf("finished execution (%d)\n", getpid());
		return (0);
	}

	// int pid1_res = wait(NULL);
	// printf("Waited for %d\n", pid1_res);
	// int pid2_res = wait(NULL);
	// printf("Waited for %d\n", pid2_res);

	// int pid1_res = waitpid(pid1, NULL, 0);
	// printf("Waited for %d\n", pid1_res);
	// int pid2_res = waitpid(pid2, NULL, 0);
	// printf("Waited for %d\n", pid2_res);

	int pid1_res = waitpid(pid1, NULL, WNOHANG);
	printf("Waited for %d\n", pid1_res);
	int pid2_res = waitpid(pid2, NULL, WNOHANG);
	printf("Waited for %d\n", pid2_res);

	return (0);
}
