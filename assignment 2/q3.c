#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

long long factorial(int x) {
    long long fact = 1;
    for (int i = 1; i <= x; i++)
        fact *= i;
    return fact;
}

void fibonacci(int m) {
    int a = 0, b = 1, c;

    printf("Fibonacci numbers for %d numbers: ", m);

    for (int i = 0; i < m; i++) {
        printf("%d ", a);
        c = a + b;
        a = b;
        b = c;
    }
    printf("\n");
}

int main() {

    printf("Name: Rudra Baunk\n");

    int n, m;

    printf("Enter n for factorial: ");
    scanf("%d", &n);

    printf("Enter m for fibonacci (m >> n): ");
    scanf("%d", &m);

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    if (pid > 0) {

        printf("Hi! I am a parent process.\n");
        printf("My PID is %d.\n", getpid());
        printf("Factorial for number %d: %lld.\n", n, factorial(n));
        printf("I am terminated earlier than my child.\n");

        exit(0);
    }
    else {

        sleep(2);

        printf("Hi! I am a child process.\n");
        printf("My PID is %d.\n", getpid());
        printf("MY Parent PID is %d.\n", getppid());

        fibonacci(m);
    }

    return 0;
}
