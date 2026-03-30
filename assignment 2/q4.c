#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {

    printf("Name: Rudra Baunk\n");

    pid_t Q, R, S, T, U;

    printf("Hi! I am a root process P.\n");
    printf("My PID is %d.\n", getpid());

    Q = fork();

    if (Q < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (Q == 0) {

        printf("Hi! I am a child process Q of Parent P.\n");
        printf("My PID is %d.\n", getpid());
        printf("MY Parent PID is %d.\n", getppid());

        S = fork();

        if (S == 0) {
            printf("Hi! I am a child process S of Parent Q.\n");
            printf("My PID is %d.\n", getpid());
            printf("MY Parent PID is %d.\n", getppid());
            exit(0);
        }

        T = fork();

        if (T == 0) {
            printf("Hi! I am a child process T of Parent Q.\n");
            printf("My PID is %d.\n", getpid());
            printf("MY Parent PID is %d.\n", getppid());
            exit(0);
        }

        wait(NULL);
        wait(NULL);
        exit(0);
    }
    else {

        R = fork();

        if (R == 0) {

            printf("Hi! I am a child process R of Parent P.\n");
            printf("My PID is %d.\n", getpid());
            printf("MY Parent PID is %d.\n", getppid());

            U = fork();

            if (U == 0) {
                printf("Hi! I am a child process U of Parent R.\n");
                printf("My PID is %d.\n", getpid());
                printf("MY Parent PID is %d.\n", getppid());
                exit(0);
            }

            wait(NULL);
            exit(0);
        }

        wait(NULL);
        wait(NULL);
    }

    return 0;
}
