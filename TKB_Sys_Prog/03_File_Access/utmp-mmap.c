#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <utmp.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>

int main(void)
{
    int fd, num, err;
    struct stat fs;
    struct utmp *u0, *u;
    size_t maplen;

    fd = open(_PATH_UTMP, O_RDONLY);
    if (fd < 0)
    {
        perror(_PATH_UTMP);
        exit(-1);
    }

    if (fstat(fd, &fs) < 0)
    {
        perror("fstat");
        exit(-1);
    }

    /* The size of a mapped area must be a multiple of pagesize */
    for (maplen = fs.st_size;
         maplen % sysconf(_SC_PAGE_SIZE) != 0;
         maplen++)
        ;

    u0 = u = mmap(NULL, maplen, PROT_READ, MAP_PRIVATE, fd, 0);
    if (u == MAP_FAILED)
    {
        perror("mmap");
        exit(-1);
    }

    num = fs.st_size / sizeof(struct utmp);

    while (num--)
    {
        if (u->ut_type != DEAD_PROCESS)
        {
            time_t t = u->ut_time;
            printf("%8.8s|%16.16s|%8.8s|%s", u->ut_name,
                   u->ut_host, u->ut_line, ctime(&t));
        }
        u++;
    }

    err = munmap(u0, maplen);
    if (err)
    {
        perror("munmap");
        exit(-1);
    }
    close(fd);

    return 0;
}
