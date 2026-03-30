#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/wait.h>

#define SIZE 10

unsigned long fact(int n) {
    unsigned long res = 1;
    for (int i = 2; i <= n; i++) res *= i;
    return res;
}
int main() {
    key_t key = 91011;
    int shmid = shmget(key, SIZE * sizeof(int), 0666 | IPC_CREAT);
    int *ptr = (int*) shmat(shmid, NULL, 0);
    int arr[SIZE] = {3, 4, 5, 2, 6, 3, 4, 5, 2, 3};
    for(int i = 0; i < SIZE; i++) ptr[i] = arr[i];

    for (int i = 1; i <= 3; i++) {
        if (fork() == 0) { 
            if (i == 1) { 
                for (int j = 0; j < 4; j++) printf("C1 (Fact %d): %lu\n", ptr[j], fact(ptr[j]));
            } else if (i == 2) { 
                for (int j = 4; j < 6; j++) printf("C2 (Fact %d): %lu\n", ptr[j], fact(ptr[j]));
            } else { 
                for (int j = 6; j < 10; j++) printf("C3 (Fact %d): %lu\n", ptr[j], fact(ptr[j]));
            }
            exit(0);
        }
    }
    for (int i = 0; i < 3; i++) wait(NULL);
    shmdt(ptr);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}