#include <unistd.h>

extern char **environ;

int main(void)
{
        char *argv[2];

        argv[0] = "ls";
        argv[1] = NULL;

        execve("/bin/ls", argv, environ);

        return 0;
}
