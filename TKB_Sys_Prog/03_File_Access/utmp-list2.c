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

struct utmplist *read_utmp(FILE *fp, struct utmplist *head)
{
    struct utmplist *ulprev, *ulp;

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

        if (head == NULL)
        {
            head = ulp;
        }
        else
        {
            ulprev->next = ulp;
        }

        ulprev = ulp;
    }

    return head;
}

void write_utmp(FILE *fp, struct utmplist *head)
{
    struct utmplist *ulprev;
    struct utmplist *ulp = head;

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
}

int main(void)
{
    FILE *fp;
    struct utmplist *ulhead = NULL;

    fp = fopen(_PATH_UTMP, "r");
    if (fp == NULL)
    {
        perror(_PATH_UTMP);
        exit(-1);
    }

    ulhead = read_utmp(fp, ulhead);

    fclose(fp);

    write_utmp(stdout, ulhead);

    return 0;
}
