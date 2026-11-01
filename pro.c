
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define SIZE 5

int buffer[SIZE], count=0;
pthread_mutex_t mutex;
sem_t full, empty;

void *producer(void *arg)
{
int i;
for(i=0;i<5;i++)
{
sem_wait(&empty);
pthread_mutex_lock(&mutex);
buffer[count++]=i+1;
printf("producer produced %d\n",i+1);
pthread_mutex_unlock(&mutex);
sem_post(&full);
}
return NULL;
}

void *consumer(void *arg)
{
int i,item;
for(i=0;i<5;i++)
{
sem_wait(&full);
pthread_mutex_lock(&mutex);
item=buffer[--count];
printf("consumer consumed %d\n",item);
pthread_mutex_unlock(&mutex);
sem_post(&empty);
}
return NULL;
}

int main()
{
pthread_t p,c;

pthread_mutex_init(&mutex,NULL);
sem_init(&empty,0,SIZE);
sem_init(&full,0,0);

pthread_create(&p,NULL,producer,NULL);
pthread_create(&c,NULL,consumer,NULL);

pthread_join(p,NULL);
pthread_join(c,NULL);

printf("Exit the program\n");
return 0;
}
