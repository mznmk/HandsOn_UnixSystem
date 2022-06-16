#include <unistd.h>
#include <stdio.h>

//     v (vector->argument)
// exec                    p (path) e (environment variable)
//     l (list)

int	main(int argc, char **argv)
{
	execlp(
		"ping",
		"ping",
		"-c",
		"3",
		"google.com",
		NULL
	);

	// if error happen, execute below
	printf("Ping finished executing\n");

	return (0);
}
