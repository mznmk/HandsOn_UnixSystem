#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

volatile sig_atomic_t sigint_count = 3;

void sigint_handler(int signum)
{
    printf("sigint_handler: signum(%d), sigint_count(%d)\n",
           signum, sigint_count);

    if (--sigint_count <= 0)
    {
        printf("sigint_handler: exiting ...\n");
        exit(1);
    }
}

int main(void)
{
    struct sigaction sa_sigint;

    memset(&sa_sigint, 0, sizeof(sa_sigint));
    sa_sigint.sa_handler = sigint_handler;
    sa_sigint.sa_flags = SA_RESTART;

    if (sigaction(SIGINT, &sa_sigint, NULL) < 0)
    {
        perror("sigaction");
        exit(1);
    }

    for (;;)
    {
        printf("main: sigint_count(%d), calling pause ...\n",
               sigint_count);

        pause();

        printf("main: returned from pause. sigint_count(%d)\n",
               sigint_count);
    }

    return 0;
}
