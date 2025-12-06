//Task 4 by Eman Sarah Afi (A00051) & Yousef Elsonbaty (A00138)

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

//Declare variables
int turn = 0; // 0 for Thread A, 1 for Thread B
int threadA_val = 1;
int threadB_val = 2;
pthread_mutex_t thr;
pthread_cond_t cond;

//Thread B: Prints even numbers from 2 to 14
void *threadB(void *arg){
 	while(threadB_val <= 14) {
 		pthread_mutex_lock(&thr);
 		while(turn != 1) 
 			pthread_cond_wait(&cond, &thr);
		if (threadB_val <= 14) {
			if (threadB_val == 14)
				printf("%d\n", threadB_val);
			else
				printf("%d -> ", threadB_val);
			threadB_val += 2;
		}
		turn = 0;
		pthread_mutex_unlock(&thr);
		pthread_cond_signal(&cond);
	}
	pthread_exit(0);
}

//Thread A: Prints numbers from 1 to 7
void *threadA(void *arg){
	while(threadA_val <= 7) {
		pthread_mutex_lock(&thr);
		while(turn != 0)
			pthread_cond_wait(&cond, &thr);
		if (threadA_val <= 7) {
			printf("%d -> ", threadA_val);
			threadA_val++;
		}
		turn = 1;
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
	pthread_create(&thread1, 0, &threadA, NULL);
	pthread_create(&thread2, 0, &threadB, NULL);
	pthread_join(thread1, 0);
	pthread_join(thread2, 0);
	pthread_mutex_destroy(&thr);
	pthread_cond_destroy(&cond);
	return 0;
}
