#include <stdio.h>

#define LINE_LEN 80

int main(void)
{
    char line_buf[LINE_LEN];

    while (fgets(line_buf, LINE_LEN, stdin) != NULL)
    {
        fputs(line_buf, stdout);
    }

    return 0;
}
