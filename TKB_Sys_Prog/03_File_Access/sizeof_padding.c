#include <stdio.h>

struct x
{
    char a;
    short b;
};

int main(void)
{
    printf("sizeof(char) = %ld\n", sizeof(char));
    printf("sizeof(short) = %ld\n", sizeof(short));
    printf("sizeof(struct x) = %ld\n", sizeof(struct x));
    return 0;
}
