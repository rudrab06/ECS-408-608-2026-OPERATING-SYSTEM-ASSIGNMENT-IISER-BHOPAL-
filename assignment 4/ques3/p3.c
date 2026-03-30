#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define SIZE 10000

int arr[SIZE];
pthread_mutex_t lock;

void *process_array(void *arg) {
    pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
    pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, NULL);

    for (int i = 0; i < SIZE; i++) {
        pthread_mutex_lock(&lock);
        printf("%d ", (arr[i] + 2) * 4);
        pthread_mutex_unlock(&lock);
        pthread_testcancel();
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;
    printf("Name: Rudra Baunk | Roll number: 22268\n");

    pthread_mutex_init(&lock, NULL);

    for (int i = 0; i < SIZE; i++)
        arr[i] = i;

    pthread_create(&t1, NULL, process_array, NULL);
    pthread_create(&t2, NULL, process_array, NULL);

    sleep(1);

    pthread_cancel(t1);
    pthread_cancel(t2);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock);

    printf("\nThreads cancelled after 1 second\n");
    return 0;
}