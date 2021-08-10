#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int x;
	printf("input number: ");
	scanf("%d", &x);
	printf("Result %d * 5 = %d\n", x, x * 5);

	return (0);
}
