#include <stdio.h>
#include <string.h>
#include <sys/param.h>

int main(void)
{
    int i;
    char line_buf[MAXPATHLEN];
    char *p, *np;

    while (fgets(line_buf, MAXPATHLEN, stdin) != NULL)
    {
        i = 0;
        p = line_buf;
        while ((np = index(p, '/')) != NULL)
        {
            *np = '\0';
            printf("%d: %s\n", i++, p);
            p = np + 1;
        }
        printf("%d: %s\n", i, p);
    }

    return 0;
}
