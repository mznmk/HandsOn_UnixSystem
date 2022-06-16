#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
	int	arr[] = {1, 2, 3, 4, 1, 2, 7, 7};
	int arrSize = sizeof(arr) / sizeof(int);	// array size
	int start, end;								// array index
	int fd[2];

	// error handling

	if (pipe(fd) == -1)
	{
		return (1);
	}

	int id = fork();
	if (id == -1)
	{
		return (2);
	}

	// set array index

	if (id == 0)			// child process
	{
		start = 0;
		end = start + arrSize / 2;
	}
	else
	{
		start = arrSize / 2;
		end = arrSize;
	}

	// Caluculate partial sum

	int sum = 0;
	int i;
	for (i = start; i < end; i++)
	{
		sum += arr[i];
	}
	printf("Caluculated partial sum: %d\n", sum);

	// Communicating between child to parent processs
	
	if (id == 0)			// child process
	{
		close(fd[0]);
		if (write(fd[1], &sum, sizeof(sum)) == -1)
			return (3);
		close(fd[1]);
	}
	else
	{
		int sumFromChild;
		close(fd[1]);
		if (read(fd[0], &sumFromChild, sizeof(sumFromChild)) == -1)
			return (4);
		close(fd[0]);

		int totalSum = sum + sumFromChild;
		printf("Total sum is %d\n", totalSum);
		wait(NULL);
	}

	return (0);
}
