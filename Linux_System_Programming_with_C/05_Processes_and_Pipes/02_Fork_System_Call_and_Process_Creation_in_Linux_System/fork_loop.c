#include <stdio.h>
#include <unistd.h>

void	main()
{
	int		i;

	if (fork())
	{
		for (i = 0; i < 100; i++)
			printf("**    Parent %d\n", i);
	}
	else
	{
		for (i = 0; i < 100; i++)
			printf("  **  Child  %d\n", i);
	}
}
