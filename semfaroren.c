#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>

#define n_itens 500
int buffer[n_itens],c=0;

pthread_mutex_t mutex;
pthread_cond_t condp,condd;

void *producer();
void *consumer();

void *producer(){
	int i=0;
	while(i<n_itens){
		pthread_mutex_lock(&mutex);
		if(c==500){
			pthread_cond_wait(&condp,&mutex);			
		}
		buffer[c] = i;
		printf("produced, %d\n",i);
		c++;
		i++;
		if(c==1){
			printf("producer says: acorde consumidor !\n");
			pthread_cond_signal(&condd); 
		}
		pthread_mutex_unlock(&mutex);
	}
	pthread_exit(0);
}

void *consumer(){
	int i=0;
	pthread_mutex_lock(&mutex);
	while(i<n_itens){
		if(c == 0){
			printf("consumer says: sleep time !\n");
			pthread_cond_wait(&condd,&mutex);
		}
		buffer[c]=0;
		printf("consumed, %d\n",c-1);
		c--;
		i++;
		if(c==499){
			printf("consumer says: wake up producer !\n");
			pthread_cond_signal(&condp);
		}
		pthread_mutex_unlock(&mutex);
	}
	pthread_exit(0);
}

main(){
	pthread_t pro,con;
	pthread_mutex_init(&mutex,0);
	pthread_cond_init(&condp,0);
	pthread_cond_init(&condd,0);
	pthread_create(&pro,0,producer,0);
	pthread_create(&con,0,consumer,0);
	pthread_join(pro,0);
	pthread_join(con,0);
	pthread_cond_destroy(&condp);
	pthread_cond_destroy(&condd);
	pthread_mutex_destroy(&mutex);
}
















	
		










