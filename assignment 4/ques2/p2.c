#include <stdio.h>
#include <pthread.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int fd;

void *create_file(void *arg) {
    fd = open("data.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd < 0)
        perror("File creation failed");
    else
        printf("File created successfully\n");
    return NULL;
}

void *write_file(void *arg) {
    char buf[128];
    int n = read(0, buf, sizeof(buf));
    write(fd, buf, n);
    printf("Data written to file\n");
    close(fd);
    return NULL;
}

int main() {
    pthread_t t1, t2;
    printf("Name: RUdra Baunk | Roll number: 22268\n");

    pthread_create(&t1, NULL, create_file, NULL);
    pthread_join(t1, NULL);

    pthread_create(&t2, NULL, write_file, NULL);
    pthread_join(t2, NULL);

    return 0;
}