// Re-configure on-the-fly

#define _GNU_SOURCE

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

char	c;
int		count;

void	read_config_file(int signum)
{
	FILE	*fd;
	char	*line;
	size_t	len = 0;

	fd = fopen("./reconfigure.conf", "r");
	getline(&line, &len, fd);
	c = line[0];
	getline(&line, &len, fd);
	count = atoi(line);
	printf("read char = %c and count = %d\n", c, count);
	fclose(fd);
}

void	main()
{
	int		i;

	signal(SIGHUP, read_config_file);
	raise(SIGHUP);

	while (1)
	{
		for (i = 0; i < count; i++)
			putchar(c);
		putchar('\n');
		sleep(3);
	}
}
