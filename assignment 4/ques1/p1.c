#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *compute_sum(void *arg) {
    int *nums = (int *)arg;
    int *res = malloc(sizeof(int));
    *res = nums[0] + nums[1];
    pthread_exit((void *)res);
}

int main() {
    pthread_t t1;
    int *result;

    int nums[2] = {12, 18};
    printf("Name=Rudra Baunk | Roll number = 22268\n");

    pthread_create(&t1, NULL, compute_sum, (void *)nums);
    pthread_join(t1, (void **)&result);

    printf("Sum = %d\n", *result);
    free(result);
    return 0;
}