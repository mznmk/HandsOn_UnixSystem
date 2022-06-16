#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

//     v (vector->argument)
// exec                    p (path) e (environment variable)
//     l (list)

int	main(int argc, char **argv, char **envp)
{
	char *arr[] = {
		"ping",
		"-c",
		"3",
		"google.com",
		NULL
	};

	execvpe(
		"ping2",
		arr,
		envp
	);		// "ping2" doesn't exsit -> error happen

	// if error happen, execute below
	printf("%s\n", strerror(errno));
	printf("Ping finished executing\n");

	return (0);
}
