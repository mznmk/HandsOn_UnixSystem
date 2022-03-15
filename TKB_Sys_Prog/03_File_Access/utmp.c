#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <utmp.h>

int main(void)
{
    FILE *fp;
    struct utmp u;

    fp = fopen(_PATH_UTMP, "r");
    if (fp == NULL)
    {
        perror(_PATH_UTMP);
        exit(-1);
    }

    while (fread(&u, sizeof(u), 1, fp) == 1)
    {
        if (u.ut_type != DEAD_PROCESS)
        {
            time_t t = u.ut_time;
            printf("%8.8s|%16.16s|%8.8s|%s", u.ut_name,
                   u.ut_host, u.ut_line, ctime(&t));
        }
    }

    fclose(fp);

    return 0;
}
