#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main()
{
    int fd[2];
    pid_t pid;

    char write_msg[] = "Hello Child, this message is from Parent!";
    char read_msg[100];

    // Create pipe
    pipe(fd);

    // Create process
    pid = fork();

    if (pid > 0)
    {
        // Parent process
        close(fd[0]); // Close read end

        write(fd[1], write_msg, strlen(write_msg) + 1);

        close(fd[1]); // Close write end
    }
    else if (pid == 0)
    {
        // Child process
        close(fd[1]); // Close write end

        read(fd[0], read_msg, sizeof(read_msg));
        printf("Child process received: %s\n", read_msg);

        close(fd[0]); // Close read end
    }

    return 0;
}