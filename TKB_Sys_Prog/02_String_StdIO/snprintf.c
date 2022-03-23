#include <stdio.h>
#include <string.h>

int main(void)
{
    char buf5[5];
    char buf20[20];
    char *s1 = "01234567890";
    char *s2 = "abcdefghijklmnopqrstuvwxyz";
    int len;

    len = snprintf(buf5, sizeof(buf5), "%s", s1);
    printf("copy to buf5:  s1=\"%s\", len-s1=%d, str-in-buf=\"%s\", len-str-in-buf=%ld\n",
           s1, len, buf5, strlen(buf5));

    len = snprintf(buf20, sizeof(buf20), "%s", s1);
    printf("copy to buf20: s1=\"%s\", len-s1=%d, str-in-buf=\"%s\", len-str-in-buf=%ld\n",
           s1, len, buf20, strlen(buf20));

    len = snprintf(buf20, sizeof(buf20), "%s%s", s1, s2);
    printf("cat  to buf20: s2=\"%s\", len-s1s2=%d, str-in-buf=\"%s\", len-str-in-buf=%ld\n",
           s2, len, buf20, strlen(buf20));

    return 0;
}
