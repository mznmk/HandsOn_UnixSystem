#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>

//     v (vector->argument)
// exec                    p (path) e (environment variable)
//     l (list)

int	main(int argc, char **argv)
{
	char *arr[] = {
		"ping",
		"-c",
		"3",
		"google.com",
		NULL
	};
	char *env[] = {
		"TEST=environment variable",
		NULL
	};

	execvpe(
		"ping",
		arr,
		env
	);

	// if error happen, execute below
	printf("Ping finished executing\n");

	return (0);
}
