#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define COUNT 100
int main() {
    key_t key = 5678;
    int shmid = shmget(key, COUNT * sizeof(int), 0666 | IPC_CREAT);
    int *ptr = (int*) shmat(shmid, NULL, 0);

    srand(time(NULL));
    printf("Producer: Generating 100 random numbers...\n");
    for (int i = 0; i < COUNT; i++) {
        ptr[i] = rand() % 1000;
    }
    printf("Data successfully placed in shared memory. Run consumer now.\n");
    shmdt(ptr);
    return 0;
}