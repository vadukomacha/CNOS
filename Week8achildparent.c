#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid;

    pid = fork();

    if (pid < 0)
    {
        printf("Child process creation failed\n");
    }
    else if (pid == 0)
    {
        // Child process
        printf("This is CHILD process\n");
        printf("Child PID (CID): %d\n", getpid());
        printf("Parent PID (PPID): %d\n", getppid());
    }
    else
    {
        // Parent process
        printf("This is PARENT process\n");
        printf("Parent PID: %d\n", getpid());
        printf("Child PID (CID): %d\n", pid);
    }

    return 0;
}
