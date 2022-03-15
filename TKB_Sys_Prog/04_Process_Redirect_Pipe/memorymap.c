#include <stdio.h>

extern char **environ;

int data0;
int data1 = 10;

int main(int argc, char *argv[])
{
    char c;

    printf("data:\t\t%p\n", &data1);
    printf("bss:\t\t%p\n", &data0);

    printf("stack:\t\t%p\n", &c);

    printf("argv:\t\t%p\n", argv);
    printf("environ:\t%p\n", environ);

    return 0;
}
