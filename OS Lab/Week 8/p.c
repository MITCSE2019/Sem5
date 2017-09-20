#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
#define bufferBound 10
sem_t semaphore,bound;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int queue[bufferBound];
int queueLength;
void *producer( void * param)
{
    for ( int i=0; i<50; i++ )
    {
        // Add item to queue
        sem_wait(&bound);
        pthread_mutex_lock( &mutex );
        queue[ queueLength++ ] = i;
        printf("Sent %d\n", i);
        pthread_mutex_unlock( &mutex );
        // Signal semaphore
        sem_post( &semaphore );
    }
}
void *consumer(void * param)
{
    for ( int i=0; i<50; i++ )
    {
        int item;
        // Wait if nothing in queue
        sem_wait(&semaphore);
        pthread_mutex_lock( &mutex );
        item = queue[ -- queueLength ];
        printf("Received %i\n", item);
        pthread_mutex_unlock( &mutex );
 
        sem_post(&bound);
    }
}
int main()
{
    pthread_t threads[2];
    sem_init( &semaphore, 0, 0 );
    sem_init( &bound,0,bufferBound);
    pthread_create( &threads[0], 0, producer, 0 );
    pthread_create( &threads[1], 0, consumer, 0 );
    pthread_join( threads[0], 0 );
    pthread_join( threads[1], 0 );
    sem_destroy( &semaphore );
}
