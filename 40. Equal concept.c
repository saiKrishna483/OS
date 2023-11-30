#include <stdio.h>
#include <pthread.h>

void *threadFunction(void *arg) {
    printf("Hello from the new thread!\n");
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, threadFunction, NULL);
    pthread_create(&thread2, NULL, threadFunction, NULL);
    if (pthread_equal(thread1, thread2)) {
        printf("The threads are equal.\n");
    } else {
        printf("The threads are not equal.\n");
    }
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    return 0;
}
