#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *buf;
    char *s1 = "01234567890";
    char *s2 = "abcdefghijklmnopqrstuvwxyz";
    int len;

    buf = malloc(5);
    if (buf == NULL)
    {
        perror("malloc");
        exit(1);
    }

    len = strlcpy(buf, s1, 5);
    printf("copy to buf: s1=\"%s\", len-s1=%d, str-in-buf=\"%s\", len-str-in-buf=%ld\n",
           s1, len, buf, strlen(buf));

    buf = malloc(20);
    if (buf == NULL)
    {
        perror("malloc");
        exit(1);
    }

    len = strlcat(buf, s2, 20);
    printf("cat  to buf: s2=\"%s\", len-bufs2=%d, str-in-buf=\"%s\", len-str-in-buf=%ld\n",
           s2, len, buf, strlen(buf));

    free(buf);

    return 0;
}
