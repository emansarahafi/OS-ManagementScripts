//Task 4 by Eman Sarah Afi (A00051) & Yousef Elsonbaty (A00138)

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

//Declare variables
int MAX = 14;
int thread1val = 0;
int thread2val = 0;
int count = 1;
int thread1count = 1;
int thread2count = 2;
pthread_mutex_t thr;
pthread_cond_t cond;

//Prints all even values from 2 to 14 and should be used alongside the all function
void *even(void *arg){
 	while(count < MAX) {
 		pthread_mutex_lock(&thr);
 		while(count % 2 != 0) 
 			pthread_cond_wait(&cond, &thr);
		if (count != MAX)
			printf("%d -> ", thread2val + thread2count);
		else
			printf("%d\n ", thread2val + thread2count);
		thread2val = thread2val + thread2count;
		count++;
		pthread_mutex_unlock(&thr);
		pthread_cond_signal(&cond);
	}
	pthread_exit(0);
}

//Prints all values from 1 to 14 and should be used alongside the even function
void *all(void *arg){
	while(count < MAX) {
		pthread_mutex_lock(&thr);
		while(count % 2 != 1)
			pthread_cond_wait(&cond, &thr);
		printf("%d -> ", thread1val + thread1count);
		thread1val = thread1val + thread1count;
		count++;
		pthread_mutex_unlock(&thr);
		pthread_cond_signal(&cond);
	}
	pthread_exit(0);
}

//Main Function
int main(){
	pthread_t thread1;
	pthread_t thread2;
	pthread_mutex_init(&thr, 0);
	pthread_cond_init(&cond, 0);
	pthread_create(&thread1, 0, &even, NULL);
	pthread_create(&thread2, 0, &all, NULL);
	pthread_join(thread1, 0);
	pthread_join(thread2, 0);
	pthread_mutex_destroy(&thr);
	pthread_cond_destroy(&cond);
	return 0;
}
