#include <stdio.h>

char s[] = {'H', 'e', 'l', 'l', 'o', 0};

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
