#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *buf5;
    char *buf20;
    char *s1 = "01234567890";
    char *s2 = "abcdefghijklmnopqrstuvwxyz";
    int len;

    buf5 = malloc(5);
    if (buf5 == NULL)
    {
        perror("malloc");
        exit(1);
    }

    buf20 = malloc(20);
    if (buf20 == NULL)
    {
        perror("malloc");
        exit(1);
    }
    bzero(buf20, 20); /* fill the buffer with zero */

    len = strlcpy(buf5, s1, 5);
    printf("copy to buf5: s1=\"%s\", len-s1=%d, str-in-buf=\"%s\", len-str-in-buf=%ld\n",
           s1, len, buf5, strlen(buf5));

    len = strlcat(buf5, s2, 20);
    printf("cat  to buf5: s2=\"%s\", len-buf5s2=%d, str-in-buf=\"%s\", len-str-in-buf=%ld\n",
           s2, len, buf5, strlen(buf5));

    printf("buf20: str-in-buf=\"%s\", len-str-in-buf=%ld\n", buf20, strlen(buf20));

    free(buf5);
    free(buf20);

    return 0;
}
