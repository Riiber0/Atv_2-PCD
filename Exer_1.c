#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

#define numT 1

int soma = 0, turn, request = 0, respond = 0;

void *servidor(void* arg){
	printf("server on\n");
	while(1){
		while(request == 0);
		respond = request;
		while(respond != 0);
		request = 0;
	}

	pthread_exit(NULL);
}

void *cliente(void* arg){
	int i = *(int*)arg + 1;
	printf("thread %d criada\n", i);

	for(int c = 0; c < 10; c++){
		while(respond != i) request = i;
		soma++;
		sleep(rand()%2);
		respond = 0;
	}
	printf("fim thread %d", i);

	pthread_exit(NULL);
}

int main(int argc, char** argv){
	pthread_t t[numT + 1];

	pthread_create(&t[numT], NULL, servidor, NULL);
	for(int i = 0; i < numT; i++){
		int* aux = (int*)malloc(sizeof(int));
		*aux = i;
		pthread_create(&t[i], NULL, cliente, aux);
	}
	pthread_join(t[0], NULL);
	printf("%d\n",soma);

	return 0;
}
