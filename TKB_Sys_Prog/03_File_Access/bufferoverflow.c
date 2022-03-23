#include <stdio.h>
#include <string.h>

char *longstr = "01234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

void copy_with_check(char *src)
{
    char dst[20];
    int len;

    puts("copy_with_check");
    printf("src=\"%s\".\n", src);

    len = strlcpy(dst, src, sizeof(dst));
    if (len > sizeof(dst) - 1)
    {
        printf("dst is too short to copy.\n");
    }

    printf("dst=\"%s\"\n", dst);
}

void copy_without_check(char *src)
{
    char dst[20];

    puts("copy_without_check");
    printf("src=\"%s\".\n", src);

    strcpy(dst, src);

    printf("dst=\"%s\"\n", dst);
}

int main(void)
{
    copy_with_check(longstr);
    copy_without_check(longstr);
    return 0;
}
