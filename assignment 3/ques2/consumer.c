#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define COUNT 100

int main() {
    key_t key = 5678;
    int shmid = shmget(key, COUNT * sizeof(int), 0666);
    int *ptr = (int*) shmat(shmid, NULL, 0);

    long sum = 0;
    for (int i = 0; i < COUNT; i++) {
        sum += ptr[i];
    }
    printf("Consumer: Cumulative sum of 100 numbers is: %ld\n", sum);
    shmdt(ptr);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}