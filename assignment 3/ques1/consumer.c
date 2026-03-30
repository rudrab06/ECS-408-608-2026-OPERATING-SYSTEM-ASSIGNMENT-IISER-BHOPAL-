#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>

struct SharedData {
    int user_num;
    char user_str[100];
};

int main() {
    key_t key = 1234;
    int shmid = shmget(key, sizeof(struct SharedData), 0666);
    struct SharedData *ptr = (struct SharedData*) shmat(shmid, NULL, 0);
    printf("String received: %s\n", ptr->user_str);
    if (ptr->user_num % 2 == 0)
        printf("The number %d is EVEN.\n", ptr->user_num);
    else
        printf("The number %d is ODD.\n", ptr->user_num);
    shmdt(ptr);
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}