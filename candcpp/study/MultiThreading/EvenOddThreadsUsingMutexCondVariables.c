#include<stdio.h>
#include<pthread.h>
#include<errno.h>

pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
int idx = 0;
int count = 0;

void* even_func(void* p)
{
	while(count < 10) {
#if 0 //Only mutex
		pthread_mutex_lock(&mut);
                if(count%2 == 0)
		printf("thread1 : %d\n", count++);
		pthread_mutex_unlock(&mut); //just unlock
#endif
#if 1 //mutex + cond variables
		pthread_mutex_lock(&mut);
		if(idx == 1)     //While is mandatory, if we have more than 2threads
			pthread_cond_wait(&cond, &mut); //unlock and sleep

		printf("thread1 : %d\n", count++);
		idx = 1;
		int rc=pthread_mutex_unlock(&mut); //just unlock
                if(rc)
                perror("Even Fail");
		pthread_cond_broadcast(&cond); //wake from sleep,if we have more than 2threads
#endif
	}
}

void* odd_func(void* p)
{
	while(count < 10) {
#if 0 //Only mutex
		pthread_mutex_lock(&mut);
                if(count%2 == 1)
		printf("thread1 : %d\n", count++);
		pthread_mutex_unlock(&mut); //just unlock
#endif
#if 1 //mutex + cond variables
		pthread_mutex_lock(&mut);
		if(idx == 0)     //While is mandatory, if we have more than 2threads
			pthread_cond_wait(&cond, &mut); //unlock and sleep

		printf("thread1 : %d\n", count++);
		idx = 0;
		int rc=pthread_mutex_unlock(&mut); //just unlock
                if(rc)
                perror("Odd Fail");
		pthread_cond_broadcast(&cond); //wake from sleep
#endif
	}
}

int main (void)
{
	pthread_t th_id1;
	pthread_t th_id2;

	pthread_create(&th_id1, NULL, even_func, NULL);
	pthread_create(&th_id2, NULL, odd_func, NULL);

	pthread_exit(NULL);
}
