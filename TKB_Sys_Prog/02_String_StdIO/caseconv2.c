#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define LINE_LEN 80

int main(void)
{
    int i, len;
    char line_buf[LINE_LEN];
    char *p;

    while (fgets(line_buf, LINE_LEN, stdin) != NULL)
    {
        len = strlen(line_buf);
        p = line_buf;
        for (i = 0; i < len; i++, p++)
        {
            if (islower(*p))
            {
                *p = toupper(*p);
            }
            else if (isupper(*p))
            {
                *p = tolower(*p);
            }
        }
        fputs(line_buf, stdout);
    }

    return 0;
}
