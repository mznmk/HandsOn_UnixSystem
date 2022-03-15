#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int pipe_fd[2];

void do_child(void)
{
    char *p = "Hello, dad or mam!\n";

    printf("This is child.\n");

    close(pipe_fd[0]);

    close(1);
    if (dup2(pipe_fd[1], 1) < 0)
    {
        perror("dup2 (child)");
        exit(1);
    }
    close(pipe_fd[1]);

    while (*p)
    {
        putchar(*p++);
    }
}

void do_parent(void)
{
    char c;
    int status;

    printf("This is parent.\n");

    close(pipe_fd[1]);

    close(0);
    if (dup2(pipe_fd[0], 0) < 0)
    {
        perror("dup2 (parent)");
        exit(1);
    }
    close(pipe_fd[0]);

    while ((c = getchar()) != EOF)
    {
        putchar(c);
    }

    if (wait(&status) < 0)
    {
        perror("wait");
        exit(1);
    }
}

int main(void)
{
    int child;

    if (pipe(pipe_fd) < 0)
    {
        perror("pipe");
        exit(1);
    }

    if ((child = fork()) < 0)
    {
        perror("fork");
        exit(1);
    }

    if (child)
    {
        do_parent();
    }
    else
    {
        do_child();
    }

    return EXIT_SUCCESS;
}
