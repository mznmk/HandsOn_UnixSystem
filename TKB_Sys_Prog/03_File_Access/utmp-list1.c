#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include <utmp.h>

struct utmplist
{
    struct utmplist *next;
    struct utmp u;
};

int main(void)
{
    FILE *fp;
    struct utmplist *ulhead = NULL;
    struct utmplist *ulprev, *ulp;

    fp = fopen(_PATH_UTMP, "r");
    if (fp == NULL)
    {
        perror(_PATH_UTMP);
        exit(-1);
    }

    for (;;)
    {
        ulp = calloc(1, sizeof(struct utmplist));
        if (ulp == NULL)
        {
            perror("calloc");
            fclose(fp);
            exit(-1);
        }

        if (fread(&ulp->u, sizeof(ulp->u), 1, fp) != 1)
        {
            free(ulp);
            break;
        }

        if (ulhead == NULL)
        {
            ulhead = ulp;
        }
        else
        {
            ulprev->next = ulp;
        }

        ulprev = ulp;
    }

    fclose(fp);
    ulp = ulhead;

    while (ulp)
    {
        if (ulp->u.ut_type != DEAD_PROCESS)
        {
            time_t t = ulp->u.ut_time;
            printf("%8.8s|%16.16s|%8.8s|%s", ulp->u.ut_name,
                   ulp->u.ut_host, ulp->u.ut_line, ctime(&t));
        }
        ulprev = ulp;
        ulp = ulp->next;
        free(ulprev);
    }

    return 0;
}
