#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char **argv)
{
	int id1 = fork();
	int id2 = fork();

	if (id1 == 0)									// 1st fork()'s child
	{
		if (id2 == 0)
			printf("We are process y\n");			// 2nd fork()'s child
		else
			printf("We are process x\n");			// 2nd fork()'s parent
	}
	else
	{
		if (id2 == 0)								// 1st fork()'s parent
			printf("We are process z\n");			// 2nd fork()'s child
		else
			printf("We are the parent process\n");	// 2nd fork()'s parent
	}

	while (wait(NULL) != -1 || errno != ECHILD)		// wait(NULL) != -1 => have no child
	{
		printf("Waited for a child to finish ...\n");
	}

	return (0);
}
