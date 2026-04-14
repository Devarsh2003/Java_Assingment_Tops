#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define NUM_THREADS 4
#define INCREMENTS 1000000
long long counter = 0;
pthread_mutex_t counter_mutex;
void *worker(void *arg)
{
    for (int i = 0; i < INCREMENTS; i++)
    {
        pthread_mutex_lock(&counter_mutex);
        counter++;
        pthread_mutex_unlock(&counter_mutex);
    }
    return NULL;
}
int main()
{
    pthread_t threads[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; i++)
    {
        if (pthread_mutex_init(&counter_mutex, NULL) != 0)
        {
            perror("pthread_mutex_init");
            return 1;
        }
        if (pthread_create(&threads[i], NULL, worker, NULL) != 0)
        {
            perror("pthread_create");
            return 1;
        }
    }
    for (int i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }
    pthread_mutex_destroy(&counter_mutex);
    printf("Final counter value: %lld (expected %d)\n",
           counter, NUM_THREADS * INCREMENTS);
    return 0;
}