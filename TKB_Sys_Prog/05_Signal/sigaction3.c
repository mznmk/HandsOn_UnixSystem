#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

volatile sig_atomic_t sigint_count = 3;

int main(void)
{
    struct sigaction sa_ignore;

    memset(&sa_ignore, 0, sizeof(sa_ignore));
    sa_ignore.sa_handler = SIG_IGN;

    if (sigaction(SIGINT, &sa_ignore, NULL) < 0)
    {
        perror("sigaction");
        exit(1);
    }

    while (1)
    {
        printf("main: sigint_count(%d), calling pause ...\n",
               sigint_count);

        pause();

        printf("main: returned from pause. sigint_count(%d)\n",
               sigint_count);
    }

    return 0;
}
