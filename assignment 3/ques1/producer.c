#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

struct SharedData {
    int user_num;
    char user_str[100];
};

int main() {
    key_t key = 1234;
    int shmid = shmget(key, sizeof(struct SharedData), 0666 | IPC_CREAT);
    struct SharedData *ptr = (struct SharedData*) shmat(shmid, NULL, 0);
    printf("Enter an integer: ");
    scanf("%d", &ptr->user_num);
    printf("Enter a string: ");
    scanf("%s", ptr->user_str);
    printf("Data written to memory. Run consumer now.\n");
    shmdt(ptr);
    return 0;
}