
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdint.h>

sem_t room,spoon[5];

void *phil(void *arg)
{
int i=(int)(intptr_t)arg;
sem_wait(&room);
printf("Philospher %d enters\n",i);
sem_wait(&spoon[i]);
sem_wait(&spoon[(i+1)%5]);
printf("Philosopher %d is eating\n\n",i);
sleep(2);
sem_post(&spoon[i]);
sem_post(&spoon[(i+1)%5]);
printf("Philosopher %d has finished eating\n\n",i);
sem_post(&room);
return NULL;
}

int main()
{
int i;
pthread_t philosopher[5];
sem_init(&room,0,4);
for(i=0;i<5;i++)
sem_init(&spoon[i],0,1);
for(i=0;i<5;i++)
pthread_create(&philosopher[i],NULL,phil,(void *)(intptr_t)i);
for(i=0;i<5;i++)
pthread_join(philosopher[i],NULL);
return 0;
}
