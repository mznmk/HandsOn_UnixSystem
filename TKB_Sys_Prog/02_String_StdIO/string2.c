#include <stdio.h>

char s[] = "Hello";

int main(void)
{
    int i = 0;

    printf("%s\n", s);

    while (s[i])
    {
        printf("[%d] = %c\n", i, s[i]);
        i++;
    }

    return 0;
}
