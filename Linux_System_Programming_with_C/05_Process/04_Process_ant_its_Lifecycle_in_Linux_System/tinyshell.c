#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

// A minimal shell
void	main()
{
	char	line[100];

	// Main command loop
	while (printf("> "), scanf("%s", line) != 0)
	{
		if (fork() == 0)
		{
			// Child Process
			execlp(line, line, (char *)0);

			// Don't come here unless execlp fails
			printf("%s: not found\n", line);
			exit(1);
		}
		else
		{
			// Parent Process
			wait(0);
		}

		// Now loop back and prompt again

	}
}
