#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define BUFFER_SIZE 5
#define NUM_ITEMS 10
int buffer[BUFFER_SIZE];
int in = 0, out = 0;
pthread_mutex_t buffer_mutex;
sem_t empty_slots;
sem_t full_slots;
void *producer(void *arg)
{
    for (int i = 0; i < NUM_ITEMS; i++)
    {
        int item = i;
        sem_wait(&empty_slots);
        pthread_mutex_lock(&buffer_mutex);
        buffer[in] = item;
        printf("Producer: produced %d at index %d\n", item, in);
        in = (in + 1) % BUFFER_SIZE;
        pthread_mutex_unlock(&buffer_mutex);
        sem_post(&full_slots);
        usleep(100000);
    }
    return NULL;
}
void *consumer(void *arg)
{
    for (int i = 0; i < NUM_ITEMS; i++)
    {
        sem_wait(&full_slots);
        pthread_mutex_lock(&buffer_mutex);
        int item = buffer[out];
        printf("Consumer: consumed %d from index %d\n", item, out);
        out = (out + 1) % BUFFER_SIZE;
        pthread_mutex_unlock(&buffer_mutex);
        sem_post(&empty_slots);
        usleep(150000);
    }
    return NULL;
}
int main()
{
    pthread_t prod_thread, cons_thread;
    if (pthread_mutex_init(&buffer_mutex, NULL) != 0)
    {
        perror("pthread_mutex_init");
        return 1;
    }
    if (sem_init(&empty_slots, 0, BUFFER_SIZE) == -1)
    {
        perror("sem_init empty_slots");
        return 1;
    }
    if (sem_init(&full_slots, 0, 0) == -1)
    {
        perror("sem_init full_slots");
        return 1;
    }
    if (pthread_create(&prod_thread, NULL, producer, NULL) != 0)
    {
        perror("pthread_create producer");
        return 1;
    }
    if (pthread_create(&cons_thread, NULL, consumer, NULL) != 0)
    {
        perror("pthread_create consumer");
        return 1;
    }
    pthread_join(prod_thread, NULL);
    pthread_join(cons_thread, NULL);
    pthread_mutex_destroy(&buffer_mutex);
    sem_destroy(&empty_slots);
    sem_destroy(&full_slots);
    return 0;
}