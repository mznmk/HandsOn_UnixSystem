#include <stdio.h>

int *badfunc(void)
{
    int i = 5;

    return &i;
}

int main(void)
{
    int *i = badfunc();

    printf("1: %d\n", *i);
    printf("2: %d\n", *i);

    return 0;
}
