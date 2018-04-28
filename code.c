#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<semaphore.h>
sem_t s;
void fb()
{

	printf("\nHello from fb");

}
void *fa(void *b1)
{sem_wait(&s);
		
	printf("\nHello from fa");
	sem_post(&s);
}
void *fc(void *b1)
{
	sem_wait(&s);	
	printf("\nHello from fc");
	sem_post(&s);
}
void *f1(void *args)
{
	
	pthread_t T2;
	pthread_create(&T2,NULL,fa,NULL);
	pthread_join(T2,NULL);
	fb();
	pthread_create(&T2,NULL,fc,NULL);
	
	pthread_join(T2,NULL);
	
	
}
int main()
{
	sem_init(&s,0,1);
	pthread_t T1;
	
	pthread_create(&T1,NULL,f1,NULL);
	pthread_join(T1,NULL);
	sem_destroy(&s);

}
