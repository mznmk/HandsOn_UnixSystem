#include <stdio.h>

char *ps = "Hello";

int main(void)
{
    int i = 0;

    printf("%s\n", ps);

    while (*ps)
    {
        printf("[%d] = %c\n", i, *ps);
        i++;
        ps++;
    }

    return 0;
}
