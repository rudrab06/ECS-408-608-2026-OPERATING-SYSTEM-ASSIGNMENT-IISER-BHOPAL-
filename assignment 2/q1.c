#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {

    printf("Name: Rudra Baunk\n");
    printf("--------------------------------\n");

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid == 0) {
        printf("Hi! I am a child process.\n");
        printf("My PID is %d.\n", getpid());
        printf("MY Parent PID is %d.\n", getppid());
    } 
    else {
        printf("Hi! I am a parent process.\n");
        printf("My PID is %d.\n", getpid());
        printf("My Child PID is %d.\n", pid);
        wait(NULL);
    }

    return 0;
}
