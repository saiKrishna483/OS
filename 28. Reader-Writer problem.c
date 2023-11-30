#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_READERS 10
#define MAX_WRITERS 10

int shared_data = 0;
int readers_count = 0;

sem_t mutex, write_block;

void *reader(void *arg) {
    int reader_id = *(int *)arg;
    while (1) {
        sem_wait(&mutex);
        readers_count++;
        if (readers_count == 1) {
            sem_wait(&write_block);
        }
        sem_post(&mutex);

        printf("Reader %d read shared data as %d\n", reader_id, shared_data);

        sem_wait(&mutex);
        readers_count--;
        if (readers_count == 0) {
            sem_post(&write_block);
        }
        sem_post(&mutex);

        sleep(1);
    }
}

void *writer(void *arg) {
    int writer_id = *(int *)arg;
    while (1) {
        sem_wait(&write_block);

        shared_data++;
        printf("Writer %d updated shared data to %d\n", writer_id, shared_data);

        sem_post(&write_block);

        sleep(1);
    }
}

int main() {
    pthread_t readers[MAX_READERS], writers[MAX_WRITERS];
    int reader_ids[MAX_READERS], writer_ids[MAX_WRITERS];
    int i;

    sem_init(&mutex, 0, 1);
    sem_init(&write_block, 0, 1);

    for (i = 0; i < MAX_READERS; i++) {
        reader_ids[i] = i;
        pthread_create(&readers[i], NULL, reader, &reader_ids[i]);
    }

    for (i = 0; i < MAX_WRITERS; i++) {
        writer_ids[i] = i;
        pthread_create(&writers[i], NULL, writer, &writer_ids[i]);
    }

    for (i = 0; i < MAX_READERS; i++) {
        pthread_join(readers[i], NULL);
    }

    for (i = 0; i < MAX_WRITERS; i++) {
        pthread_join(writers[i], NULL);
    }

    sem_destroy(&mutex);
    sem_destroy(&write_block);

    return 0;
}

